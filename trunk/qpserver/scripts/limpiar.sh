#!/bin/bash

cd ..
make clean 2> /dev/null >/dev/null
find . -name "*~" -exec rm {} \;
find . -name "*.a" -exec rm {} \;
find . -name "*.so" -exec rm {} \;
find src -type f -perm -0700 -exec rm {} \;
find sbase -type f -perm -0700 -exec rm {} \;

cd -
