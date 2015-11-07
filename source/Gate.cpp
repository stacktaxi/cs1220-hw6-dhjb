#include "Gate.h"

void Gate::tick() {
	if(current_time == vector->getCurrentTime()) {
		// We have already ticked this clock cycle. This means we do not need to update yet.
		return;
	}

	if((in_a && in_a->getCurrentTime() < vector->getCurrentTime()) || (in_b && in_b->getCurrentTime() < vector->getCurrentTime())) {
		// One of the inputs has not ticked this clock cycle. We can not reevaluate our current state unless all inputs are up to date with the current tick.
		return;
	}

	++current_time;

	TriState new_value = recompute();

	if(new_value != value) {
		// Delay then change to new_value.
		future_values.push({current_time+delay, new_value});
	}

	// @CONSIDER: Will we ever get more than one future_value with the same time?
	while(future_values.front().time == current_time) {
		value = future_values.front().value;
		future_values.pop();
	}

	tickOutputs();

	// We still need more ticks to run through all the future values
	if(!future_values.empty()) {
		vector->continueRunning();
	}
}

void Gate::tickOutputs() {
	for(Gate *gate : out) {
		gate->tick();
	}
}

void Gate::addOut(Gate *gate) {
	out.push_back(gate);
}

unsigned Gate::getCurrentTime() {
	return current_time;
}

TriState Gate::getValue() {
	return value;
}