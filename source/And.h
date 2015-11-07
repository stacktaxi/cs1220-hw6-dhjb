#pragma once

#include "Gate.h"

class And : public Gate {
public:
	virtual TriState recompute();
};