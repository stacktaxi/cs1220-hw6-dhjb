#pragma once

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

// @CONSIDER: perhaps vector is not the best name for this considering its functionality is more to do with the circuit than anything. Maybe rename to circuit
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

    /*
     * Tick the vector automatically, and dump the output to stdout.
     */
	void clock();

    /*
     * Tick the inputs and increase the time.
     */
	void tick();

    /*
     * Update the inputs.
     */
    void update();

    /*
     * Allow the vector to tick again.
     */
	void continueRunning();

    // Output and accessors
	void printTimeline();
	unsigned getCurrentTime();
    bool isRunning();
    std::string getName();

    /*
     * Connect scopes to vector inputs and outputs
     */
	#ifndef TERM_INAL
	void connectScopes(wxFrame*, std::vector<Scope*> &);
    #endif

	void parse();
};
