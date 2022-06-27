# Modern Win32

-----------

Modern (c++17+) wrapper classes around primarily Win32 api calls to provide RAII support for
- handles including different invalid value support via traits
- events both auto reset and manual
- slim_lock RAII wrapper around SRWLOCK

Additional classes may come over time

## Build

Using CMake to build the project which is primarily header file based so the produced dll isn't realy needed, mostly done this way as an excuse to use CMake rather than visual studio

## Testing

Testing will eventually be done using boost test and possibly google test just as an excuse to try out different testing frameworks

## Nuget Package

To build run:

	```
	nuget.exe pack modern_win32_vc143.nuspec
	```

The above command will build the 64-bit release build package.  Use modern_win32_debug_vc143.nuspec to 
build the debug equivalent.

Versions should be kept in sync between these two as they are intended to represent the same build just in different
configurations
