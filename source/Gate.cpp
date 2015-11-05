#include "Gate.h"

void Gate::addOut(Gate *gate) {
	out->push(gate);
}

void Gate::tick() {
	if(current_time == vector->getCurrentTime()) {
		// We have already ticked this clock cycle. This means we do not need to update yet.
		return;
	}
}