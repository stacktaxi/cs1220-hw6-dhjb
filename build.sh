#!/bin/bash
pushd output
clang++ -ggdb -std=c++11 -Wno-switch -Wimplicit-fallthrough -o term ../source/main.cpp
popd
