#!/bin/bash

mkdir build
cd build
cmake ../ -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
