#pragma once

#include "Gate.h"

class Not : public Gate {
public:
	Not(Gate * = nullptr);
	virtual TriState recompute();
};