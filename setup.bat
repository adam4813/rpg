mkdir build
cd build
cmake ../ -G "Visual Studio 16 2019" -A Win32 -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
