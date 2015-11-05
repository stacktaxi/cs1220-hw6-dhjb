#pragma once

class IO;

class Vector {
	unsigned current_time;
	IO *in_a;
	IO *in_b;

public:
	Vector();
	void tick();
	unsigned getCurrentTime();
};