#include "Not.h"

Not::Not(Gate *_in_a) {
	in_a = _in_a;
}

TriState Not::recompute() {
	if(in_a->getValue() == X) {
		return X;
	}
	else {
		return !in_a->getValue();
	}
}