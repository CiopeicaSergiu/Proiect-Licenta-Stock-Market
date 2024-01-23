#!/bin/sh
rm -rf builddir
mkdir builddir
cd builddir
cmake -DCMAKE_BUILD_TYPE=Release -S ../source -B .
make 