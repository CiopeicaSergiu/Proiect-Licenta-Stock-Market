#!/bin/sh
cd external/boost
git submodule init
git submodule update
cd ..
echo "./bootstrap.sh"