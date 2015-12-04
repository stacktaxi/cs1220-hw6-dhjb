#pragma once

#include "Gate.h"

class Xnor : public Gate {
    public:
        using Gate::Gate;
        virtual TriState recompute();
};
