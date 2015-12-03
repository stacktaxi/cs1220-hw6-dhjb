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
    std::vector<Gate *> outs;
};

// @CONSIDER: perhaps vector is not the best name for this considering its functionality is more to do with the circuit than anything. Maybe rename to circuit
class Vector {
	std::string name;

	unsigned current_time = 0;

	std::vector<IO *> inputs;
	std::vector<IO *> outputs;
	std::vector<Gate *> other;

	bool continue_running = true;

public:
	Vector(std::string, std::string);

	void clock();
	void tick();

	void printTimeline();
	unsigned getCurrentTime();
	void continueRunning();
    bool isRunning();

	#ifndef TERM_INAL
	    void connectScopes(wxFrame *win, std::vector<Scope*> &scopes);
    #endif

	void parse();
};
