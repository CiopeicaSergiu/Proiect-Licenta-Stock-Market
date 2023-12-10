#! /bin/sh
testToRun=""

if [ "$#" -ge 1 ]
then
    testToRun=$1
fi

gdb ./builddir/tests/SqlExecutorTest