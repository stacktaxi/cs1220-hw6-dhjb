#include "Not.h"

Not::Not(Gate *_in) {
	in[0] = _in;
}

TriState Not::recompute() {
	if(in[0]->getValue() == X) {
		return X;
	}
	else {
		return !in[0]->getValue();
	}
}