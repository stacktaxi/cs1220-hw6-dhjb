// Represents either an input or an output

#pragma once

#include <string>
#include <iostream>

#include "Gate.h"

class IO : public Gate {
	std::string name;
	std::string out_dump;

public:
	IO(Vector *, unsigned, std::string);

	virtual TriState recompute();

	void dump();

	std::string getName();
	void addValue(ValueAtTime);

    // For scope
    bool isRunning();
};
