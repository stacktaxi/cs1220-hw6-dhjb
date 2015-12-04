#pragma once

#include "Gate.h"

class Xor : public Gate {
    public:
	    using Gate::Gate;
	    virtual TriState recompute();
};
