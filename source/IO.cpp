#include "IO.h"

IO::IO(std::string _name) {
	name = _name;

	// @TESTING
	if(name == "A") {
		future_values.push({2, 1});
	}
}

TriState IO::recompute() {
	return value;
}