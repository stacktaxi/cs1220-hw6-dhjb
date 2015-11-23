#include "Nor.h"

TriState Nor::recompute() {
	if(in[0]->getValue() == 0 || in[1]->getValue() == 0) {
		return 1;
	}
	else if(in[0]->getValue() == X || in[1]->getValue() == X) {
		return X;
	}
	else { // Both inputs are one.
		return 0;
	}
}