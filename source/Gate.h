// Represents a component of the circuit.
// Has two inputs and an output.
// Override this with specific gate classes (Nor, And, etc).

#pragma once

#include <climits>
#include <vector>
#include <queue>

// X represents an unknown state.
typedef unsigned TriState;
const TriState X = 2;

class Vector;

struct ValueAtTime {
	unsigned time;
	TriState value;
};

class Gate {
    protected:
        bool updated = false;
	    unsigned delay = 0;

	    // UINT_MAX is a reserved value meaning we have yet to tick the first time.
	    unsigned current_time = UINT_MAX;

        // Contains values the gate output will have a certain time.
	    std::queue<ValueAtTime> future_values;

        // The current value of the gate's output.
	    TriState value = X;

	    Gate *in[2];
	    std::vector<Gate*> out;
        Vector *my_vector;

	    unsigned next_input = 0;

    public:
	    Gate(Vector*, unsigned);

        /*
         * Gets the next future value, updates the time, then ticks the gate's
         * outputs.
         */
	    void tick();

        /*
         * Adds a new future value based on gate delay, then makes sure all
         * outputs do the same.
         */
        void update();

	    void tickOutputs();
        void updateOutputs(); 

        /*
         * This function is overridden by each gate type; simulation of each
         * gate happens in here.
         */
	    virtual TriState recompute() = 0;

        // Mutator
	    void setOutputs(std::vector<Gate*>);

        // Accessors
	    unsigned getCurrentTime();
	    TriState getValue();

	    // Function for parsing purposes.
	    void setInput(Gate*);
};
