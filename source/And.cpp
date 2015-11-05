#include "And.h"

void And::tick() {
	Gate::tick();
	if(in_a->getCurrentTime() < vector->getCurrentTime() || in_b->getCurrentTime() < vector->getCurrentTime()) {
		// One of the inputs has not ticked this clock cycle. We can not reevaluate our current state unless all inputs are up to date with the current tick.
	}

	tickOutputs();
}