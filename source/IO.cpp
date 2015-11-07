#include "IO.h"

IO::IO(std::string _name, Gate *_in_a) {
	name = _name;
	in_a = _in_a;

	// @TESTING
	if(name == "A") {
		future_values.push({0, 1});
	}
	if(name == "B") {
		future_values.push({1, 1});
	}
}

TriState IO::recompute() {
	if(in_a) {
		// We are an output. This means that we have an input, unlike inputs.
		TriState v = in_a->getValue();

		// @TESTING
		std::cout << name << " : t = " << current_time << " : ";
		if(v == X) {
			std::cout << "X";
		}
		else {
			std::cout << v;
		}
		std::cout << "\n";

		return v;
	}
	else {
		return value;
	}
}