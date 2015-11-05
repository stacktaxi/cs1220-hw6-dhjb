#pragma once

#include <vector>

class Vector;

Vector *vector;

enum TriState {
	X = 2
};

class Gate {
protected:
	unsigned delay;
	unsigned current_time;
	TriState value;

	std::vector<Gate *> out;
public:
	virtual void tick();
	void tickOutputs();

	void addOut(Gate *);

	unsigned getCurrentTime();
};