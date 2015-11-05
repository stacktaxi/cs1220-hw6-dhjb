#pragma once

#include <vector>

class Vector;

Vector *vector;

enum TriState {
	X = 2;
};

class Gate {
	unsigned delay;
	unsigned current_time;
	TriState value;

	std::vector<Gate *> out;
public:
	virtual void tick();

	void addOut(Gate *);

	unsigned getCurrentTime();
};

void tickOutputs(std::vector<Gate *> out) {
	for(Gate *gate : out) {
		out->tick();
	}
}