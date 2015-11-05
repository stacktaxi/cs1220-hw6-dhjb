#include "Gate.h"

void Gate::tick() {
	if(current_time == vector->getCurrentTime()) {
		// We have already ticked this clock cycle. This means we do not need to update yet.
		return;
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