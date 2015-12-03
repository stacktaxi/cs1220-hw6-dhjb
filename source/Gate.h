#pragma once

#include <climits>
#include <vector>
#include <queue>

typedef unsigned TriState;
const TriState X = 2;

class Vector;

struct ValueAtTime {
	unsigned time;
	TriState value;
};

class Gate {
protected:
	unsigned delay = 0;
	// UINT_MAX is a reserved value meaning we have yet to tick the first time.
	unsigned current_time = UINT_MAX;

	std::queue<ValueAtTime> future_values;
	TriState value = 0;

	Gate *in[2];
	std::vector<Gate *> out;

	Vector *my_vector;

	unsigned next_input = 0;
public:
	Gate(Vector *, unsigned);

	void tick(bool = false);
	virtual TriState recompute() = 0;

	void tickOutputs();

	void setOutputs(std::vector<Gate *>);

	unsigned getCurrentTime();
	TriState getValue();

	// Function for parsing purposes.
	void setInput(Gate *);
};
