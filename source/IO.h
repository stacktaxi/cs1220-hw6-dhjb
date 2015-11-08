// Represents either an input or an output

#pragma once

#include <string>
#include <iostream>

#include "Gate.h"

class IO : public Gate {
	std::string name;
	std::string out_dump;
public:
	IO(std::string, Gate * = nullptr);

	virtual TriState recompute();

	void dump();
};