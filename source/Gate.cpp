#include "Gate.h"

Gate::Gate(Vector *v, unsigned _delay) {
	my_vector = v;
	delay = _delay;
	value = X;
	in[0] = nullptr;
	in[1] = nullptr;
}

void Gate::tick(bool force) {
	if(current_time == my_vector->getCurrentTime()) {
		// We have already ticked this clock cycle. This means we do not need to update yet.
		return;
	}

	if(!force && ((in[0] != nullptr && (in[0]->getCurrentTime() < my_vector->getCurrentTime() || in[0]->getCurrentTime() == UINT_MAX)) || (in[1] != nullptr && (in[1]->getCurrentTime() < my_vector->getCurrentTime() || in[1]->getCurrentTime() == UINT_MAX)))) {
		// One of the inputs has not ticked this clock cycle. We can not reevaluate our current state unless all inputs are up to date with the current tick.
		return;
	}

	++current_time;

	// @CONSIDER: Will we ever get more than one future_value with the same time?
	while(!future_values.empty() && future_values.front().time == current_time) {
		value = future_values.front().value;
		future_values.pop();
	}

	TriState new_value = recompute();

	// @CONSIDER: is it a bug if the circuit delay is used even for initial circuit state (ie a nand gate connected to two inputs that default to off?). Should we do a preprocess step where we calculate what the value should be?
	if(new_value != value) {
		// Delay then change to new_value.
		if(delay != 0) {
			future_values.push({current_time+delay, new_value});
		}
		else {
			value = new_value;
		}
	}

	tickOutputs();

	// We still need more ticks to run through all the future values
	if(!future_values.empty()) {
		my_vector->continueRunning();
	}
}

void Gate::tickOutputs() {
	for(Gate *gate : out) {
		gate->tick();
	}
}

void Gate::setOutputs(std::vector<Gate *> _out) {
	out = _out;
}

unsigned Gate::getCurrentTime() {
	return current_time;
}

TriState Gate::getValue() {
	return value;
}

void Gate::setInput(Gate *_in) {
	in[next_input++] = _in;
}