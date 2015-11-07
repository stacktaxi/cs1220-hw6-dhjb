#pragma once

class IO;
class And;

class Vector {
	unsigned current_time;
	IO *in_a;
	IO *in_b;
	And *a;
	IO *out;

	bool continue_running;

public:
	Vector();
	void clock();
	unsigned getCurrentTime();
	void continueRunning();
};