
function GetVsInstallPath() {
    $programFiles = @($env:ProgramFiles, ${$env:ProgramFiles(x86)})
    $years = @('2022', '2019')
    $editions = @('Enterprise', 'Build', 'Profressional')
    $match = ""

    foreach ($basePath in $programFiles) {
        $vsDir = [System.IO.Path]::Combine($basePath, "Microsoft Visual Studio")
        if (-Not [System.String]::IsNullOrEmpty($match) -Or [System.IO.Directory]::Exists($vsDir) -ne $true) {
            continue
        }
        foreach ($year in $years) {
            $vsYear = [System.IO.Path]::Combine($vsDir, $year)
            if (-Not [System.String]::IsNullOrEmpty($match) -Or [System.IO.Directory]::Exists($vsYear) -ne $true) {
                continue
            }

            foreach ($edition in $editions) {
                $potentialPath = [System.IO.Path]::Combine($vsYear, $edition)
                if (-Not [System.String]::IsNullOrEmpty($match)) {
                    break;
                }
                if ([System.IO.Directory]::Exists($potentialPath) -eq $true) {
                    $match = $potentialPath
                } 
            }
        }
    }
    return $match
}

function GetCMakePath($vsInstallpath) {
    return [System.IO.Path]::Combine($vsInstallpath, "Common7", "IDE", "CommonExtensions", "Microsoft", "CMake", "CMake", "Bin")
}
function GetNinjaPath($vsInstallpath) {
    return [System.IO.Path]::Combine($vsInstallpath, "Common7", "IDE", "CommonExtensions", "Microsoft", "CMake", "Ninja")
}
function GetClPath($vsInstallpath) {
    $msvcPath = [System.IO.Path]::Combine($vsInstallpath, "VC", "Tools", "MSVC")
    $versions = (Get-ChildItem -Directory "$msvcPath" | Select-Object -ExpandProperty Name | Sort-Object -Descending)

    $length = @($versions).Length
    if ($length -Eq 0) {
        throw "Missing MSVC CL, unable to proceed"
    } elseif ($length -eq 1) {
        $version = $versions
        return [System.IO.Path]::Combine($msvcPath, $version, "bin", "Hostx64", "x64")
    } else {
        $version = $versions[0]
        return [System.IO.Path]::Combine($msvcPath, $version, "bin", "Hostx64", "x64")
    }
}

function GetAdditionalPaths($vsInstallpath) {

    # additional paths added when using developer command prompt / powershell
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.34.31933\bin\HostX86\x86;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\VC\VCPackages;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\TestWindow;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\MSBuild\Current\bin\Roslyn;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Team Tools\Performance Tools;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\FSharp\Tools;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\Extensions\Microsoft\CodeCoverage.Console;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\\MSBuild\Current\Bin\amd64;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\Llvm\bin;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja;
    #C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\VC\Linux\bin\ConnectionManagerExe
    #
    #C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\vs2019\;
    #C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.8 Tools\;
    #C:\Program Files (x86)\Windows Kits\10\bin\10.0.22000.0\\x86;
    #C:\Program Files (x86)\Windows Kits\10\bin\\x86;
    #C:\Program Files (x86)\HTML Help Workshop;
    #C:\Windows\Microsoft.NET\Framework\v4.0.30319;

    return ""
}


function GenerateBuildForPreset($preset) {
    cmake --preset $preset
    $result = $LASTEXITCODE
    if ($result -ne 0) {
        Write-Output "Generate build for $preset failed with $result"
        throw "Generate build failed"
        return $false
    }
    return $true
}

function Build($preset) {
    cmake --build out/build/$preset
    $result = $LASTEXITCODE
    if ($result -ne 0) {
        Write-Output "build failed with $result"
        return $false
    }
    return $true
}

$currentPath = Get-Location
$root = Split-Path -Parent $PSScriptRoot

# force running as 64-bit so $env:ProgramFiles resolves to expected location 
if (($pshome -like "*syswow64*") -and ((Get-WmiObject Win32_OperatingSystem).OSArchitecture -like "64*")) {
    & (join-path ($pshome -replace "syswow64", "sysnative")\powershell.exe) -file $myinvocation.mycommand.Definition @args
    exit
}

try {
    Set-Location $root
    $vsInstallpath = GetVsInstallPath
    if ([System.String]::IsNullOrEmpty($vsInstallpath)) {
        Write-Output "Unable to locate Visual Studio"
        return -1
    }

    $cmakePath = GetCMakePath $vsInstallpath
    Write-Output $cmakePath
    $ninjaPath = GetNinjaPath $vsInstallpath
    Write-Output $ninjaPath
    $clPath = GetClPath $vsInstallpath
    Write-Output $clPath
    #$env:Path = "$env:Path;$cmakePath;$ninjaPath;$clPath"

    $path = [System.String] $env:Path
    if ($path.Contains("CMake") -eq $true) {
        # CMAKE in path, assume using developer prompt and don't add anything
    } else {
        $additionalPath = GetAdditionalPaths
        $env:Path = "$env:Path;$additionalPath"
        # this is not working yet, hoping to eventualy get the build working outside of the developer prompt
    }

    #$presets = @('vc143-x64-release-spectre', 'vc143-x64-debug-spectre', 'vc143-x64-release', 'vc143-x64-debug')
    $presets = @('vc143-x64-release-spectre')

    foreach ($preset in $presets) {
        $result = GenerateBuildForPreset $preset
        if ($result -ne $true) {
            return -2
        }
    }

    foreach ($preset in $presets) {
        $result = Build $preset
        if ($result -ne $true) {
            return -3
        }
    }

    return 0

} catch {
    Write-Output $PSItem.Exception.Message
    return -99

} finally {
    Set-Location $currentPath
}
