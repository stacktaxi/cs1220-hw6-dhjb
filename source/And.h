#pragma once

#include "Gate.h"

class And : public Gate {
public:
	using Gate::Gate;

	virtual TriState recompute();
};