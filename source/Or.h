#pragma once

#include "Gate.h"

class Or : public Gate {
    public:
	    using Gate::Gate;
        virtual TriState recompute();
};
