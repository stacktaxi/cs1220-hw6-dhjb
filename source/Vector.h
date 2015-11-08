#pragma once

class IO;
class And;
class Not;

class Vector {
	unsigned current_time;

	// @TESTING
	IO *in_a;
	IO *in_b;
	And *a;
	Not *n;
	IO *out;

	bool continue_running = true;

public:
	Vector();
	void clock();
	void printTimeline();
	unsigned getCurrentTime();
	void continueRunning();
};