#include "And.h"

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