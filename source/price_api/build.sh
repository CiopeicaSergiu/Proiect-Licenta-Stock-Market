#!/bin/sh
rm -rf builddir
mkdir builddir
cd builddir
cmake -DCMAKE_BUILD_TYPE=Debug -S .. -B .
make