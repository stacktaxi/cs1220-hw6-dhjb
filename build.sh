#!/bin/bash

pushd output
clang++ -ggdb -DTERM_STU=1 -std=c++11 -Wno-switch -Wimplicit-fallthrough $(wx-config --cxxflags) $(wx-config --libs) -o term ../source/main.cpp
popd
