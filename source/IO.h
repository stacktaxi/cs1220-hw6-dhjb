// Represents either an input or an output

#pragma once

#include <string>
#include <iostream>

#include "Gate.h"

class IO : public Gate {
	std::string name;
	std::string out_dump;

    public:
	    IO(Vector*, unsigned, std::string);

	    virtual TriState recompute();

	    // Writes the history of the IO's value as a string to stdout.
        void dump();

	    std::string getName();

        // Used when reading values from the vector
	    void addValue(ValueAtTime);

        // For Scope
        bool isRunning();
};
