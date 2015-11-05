// Represents either an input or an output

#pragma once

#include <string>

#include "Gate.h"

class IO : public Gate {
	std::string name;
	Gate *in;
};