#pragma once

#include "Gate.h"

class Nand : public Gate {
    public:
	    using Gate::Gate;
	    virtual TriState recompute();
};
