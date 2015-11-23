#include "Or.h"

TriState Or::recompute() {
	if(in[0]->getValue() == 1 || in[1]->getValue() == 1) {
		return 1;
	}
	else if(in[0]->getValue() == X || in[1]->getValue() == X) {
		return X;
	}
	else { // Both inputs are zero.
		return 0;
	}
}