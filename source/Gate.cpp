#include "Gate.h"

Gate::Gate(Vector *v, unsigned _delay)
: my_vector(v), delay(_delay) {
	in[0] = nullptr;
	in[1] = nullptr;
}

void Gate::tick() {
    // Start of a new tick cycle, we need a new update after this
    updated = false;

	if(current_time == my_vector->getCurrentTime()) {
		// We have already ticked this clock cycle. 
        // This means we do not need to tick yet.
		return;
	}

	++current_time;

    // Get next value from future_values.
	if(!future_values.empty() && future_values.front().time == current_time) {
		value = future_values.front().value;
		future_values.pop();
	}

	tickOutputs();
}

void Gate::update() {
    if(updated) 
        // Already updated this cycle
        return;

    TriState new_value = recompute();

	if(delay != 0) {
	    // Delay then change to new_value.
		future_values.push({current_time + delay, new_value});
	}
	else {
        // The gate is an input or output. immediate change to new value.
		value = new_value;
	} 

	if(!future_values.empty()) {
	    // We still need more ticks to run through all the future values 
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
