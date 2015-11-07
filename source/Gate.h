#pragma once

#include <vector>
#include <queue>

class Vector;

Vector *vector;

typedef char TriState;
const char X = 2;

struct ValueAtTime {
	unsigned time;
	TriState value;
};

class Gate {
protected:
	unsigned delay = 0;
	unsigned current_time = 0;

	std::queue<ValueAtTime> future_values;
	TriState value = 0;

	Gate *in_a;
	Gate *in_b;
	std::vector<Gate *> out;
public:
	void tick();
	virtual TriState recompute() = 0;

	void tickOutputs();

	void addOut(Gate *);

	unsigned getCurrentTime();
	TriState getValue();
};