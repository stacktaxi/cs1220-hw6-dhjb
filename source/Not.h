#pragma once

#include "Gate.h"

class Not : public Gate {
public:
	using Gate::Gate;

	virtual TriState recompute();
};