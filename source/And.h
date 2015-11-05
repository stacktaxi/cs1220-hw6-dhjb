#pragma once

#include "Gate.h"

class And : public Gate {
	Gate *in_a;
	Gate *in_b;
};