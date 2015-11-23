#include "Xnor.h"

TriState Xnor::recompute() {
	if(in[0]->getValue() == X || in[1]->getValue() == X) {
		return X;
	}
	else if(in[0]->getValue() == in[1]->getValue()) {
		return 1;
	}
	else { // Inputs are not equal.
		return 0;
	}
}