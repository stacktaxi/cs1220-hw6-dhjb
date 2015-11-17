#pragma once

#include "Gate.h"

class And : public Gate {
public:
	And(Gate * = nullptr, Gate * = nullptr);
	virtual TriState recompute();
};