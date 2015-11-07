#include "And.h"

TriState And::recompute() {
	if(in_a->getValue() == 0 || in_b->getValue() == 0) {
		return 0;
	}
	else if(in_a->getValue() == X || in_b->getValue() == X) {
		return X;
	}
	else { // Both inputs are one.
		return 1;
	}
}