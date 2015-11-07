#pragma once

class IO;

class Vector {
	unsigned current_time;
	IO *in_a;
	IO *in_b;

	bool continue_running;

public:
	Vector();
	void clock();
	unsigned getCurrentTime();
	void continueRunning();
};