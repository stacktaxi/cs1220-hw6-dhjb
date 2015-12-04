#include "Gate.h"

Gate::Gate(Vector *v, unsigned _delay) {
	my_vector = v;
	delay = _delay;
	value = X;
	in[0] = nullptr;
	in[1] = nullptr;
}

void Gate::tick() {
    updated = false;
	if(current_time == my_vector->getCurrentTime()) {
		// We have already ticked this clock cycle. This means we do not need to update yet.
		return;
	}

    #ifdef TERM_DEBUG
        printf("Vector current time: %d\n", my_vector->getCurrentTime());
        if(in[0] != nullptr && in[1] != nullptr) 
            printf("Input current times: 1: %d; 2: %d\n", in[0]->getCurrentTime(), in[1]->getCurrentTime());
    #endif

	++current_time;

	// @CONSIDER: Will we ever get more than one future_value with the same time?
    // Get next value from future_values.
	while(!future_values.empty() && future_values.front().time == current_time) {
		value = future_values.front().value;
		future_values.pop();
	}

	tickOutputs();
}

void Gate::update() {
    if(updated) 
        return;

    TriState new_value = recompute();

	if(new_value != value) {
		// Delay then change to new_value.
		if(delay != 0) {
			future_values.push({current_time + delay, new_value});
		}
		else {
			value = new_value;
		}
	}

	// We still need more ticks to run through all the future values
	if(!future_values.empty()) {
		my_vector->continueRunning();
	} 

    updated = true;
    updateOutputs();
}

void Gate::tickOutputs() {
	for(Gate *gate : out) {
		gate->tick();
	}
}

void Gate::updateOutputs() {
    for(Gate *gate : out) {
        gate->update();
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
