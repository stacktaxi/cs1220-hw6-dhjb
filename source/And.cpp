#include "And.h"

And::And(Gate *_in_a, Gate *_in_b) {
	in[0] = _in_a;
	in[1] = _in_b;
	// @TESTING
	delay = 1;
}

TriState And::recompute() {
	if(in[0]->getValue() == 0 || in[1]->getValue() == 0) {
		return 0;
	}
	else if(in[0]->getValue() == X || in[1]->getValue() == X) {
		return X;
	}
	else { // Both inputs are one.
		return 1;
	}
}