#include "Nor.h"

TriState Nor::recompute() {
    if(in[0]->getValue() == 1 || in[1]->getValue() == 1) {
		return 0;
	}
	else if(in[0]->getValue() == X || in[1]->getValue() == X) {
		return X;
	}
	else { // Both inputs are zero.
		return 1;
	}
}
