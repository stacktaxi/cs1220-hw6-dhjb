// Contains all the circuit elements, along with an optional loop function with output.

#pragma once

#include <cctype>
#include <fstream>
#include <vector>
#include <map>

#ifndef TERM_INAL
	#include "GUI.h"
	#include "Scope.h"
#endif

class Gate;
class IO;

struct Wire {
    Gate *in;
    std::vector<Gate*> outs;
};

const unsigned MAX_RUNNING_TIME = 100;

class Vector {
	std::string name;

	unsigned current_time = 0;

	std::vector<IO*> inputs;
	std::vector<IO*> outputs;
	std::vector<Gate*> other;

	bool continue_running = true;

    public:
	    Vector(std::string, std::string);

        // Control functions

        // Tick the vector automatically, and dump the output to stdout.
	    void clock();

        // Tick each input.
        void tick();

        // Update each input.
        void update();
        
        // Allow the vector to tick again.
	    void continueRunning();

	    void printTimeline();
	    unsigned getCurrentTime();
        bool isRunning();
        std::string getName();

#ifndef TERM_INAL
        // Connect scopes to vector inputs and outputs.
	    void connectScopes(wxFrame*, std::vector<Scope*> &);
#endif
};
