#!/bin/bash

$LFLAGS

pushd output
clang++ -ggdb -DTERM_STU=1 -std=c++11 -Wno-switch -Wimplicit-fallthrough $(wx-config --cxxflags) $(wx-config --libs) -o sim-gui ../source/main.cpp
popd
