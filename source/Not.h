#pragma once

#include "Gate.h"

class Not : public Gate {
public:
	Not(Gate *);
	virtual TriState recompute();
};