#! /bin/sh
testToRun=""

if [ "$#" -ge 1 ]
then
    testToRun=$1
fi

./builddir/tests/SqlExecutorTest $testToRun