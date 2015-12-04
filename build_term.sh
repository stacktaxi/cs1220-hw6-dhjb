#!/bin/sh
# Builds the terminal version.

cd output
g++ -DTERM_STU=1 -DTERM_INAL=1 -std=c++11 -Wno-switch -Wimplicit-fallthrough -o term ../source/main.cpp
cd ..
