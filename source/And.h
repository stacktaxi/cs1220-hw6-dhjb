#pragma once

#include "Gate.h"

class And : public Gate {
public:
	And(Gate *, Gate *);
	virtual TriState recompute();
};