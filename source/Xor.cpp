#include "Xor.h"

TriState Xor::recompute() {
	if(in[0]->getValue() == X || in[1]->getValue() == X) {
		return X;
	}
	else if(in[0]->getValue() != in[1]->getValue()) {
		return 1;
	}
	else { // Inputs are equal.
		return 0;
	}
}