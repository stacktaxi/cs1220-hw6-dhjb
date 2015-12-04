#pragma once

#include "Gate.h"

class Nor : public Gate {
    public:
	    using Gate::Gate;
	    virtual TriState recompute();
};
