#include "Not.h"

TriState Not::recompute() {
	if(in[0]->getValue() == X) {
		return X;
	}
	else {
		return !in[0]->getValue();
	}
}