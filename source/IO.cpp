#include "IO.h"

IO::IO(std::string _name, Gate *_in_a) {
	name = _name;
	in_a = _in_a;

	// @TESTING
	if(name == "A") {
		future_values.push({0, 1});
		future_values.push({4, 0});
	}
	if(name == "B") {
		future_values.push({1, 1});
		future_values.push({2, X});
	}
}

TriState IO::recompute() {
	TriState v;

	if(in_a) {
		// We are an output. This means that we get our value from an input.
		v = in_a->getValue();
	}
	else {
		// We are an input. This means that by the time we get here we will already have our value for this clock cycle.
		v = value;
	}

	if(v == X) {
		out_dump.append("X");
	}
	else {
		out_dump.append(std::to_string(v));
	}

	return v;
}

void IO::dump() {
	std::cout << name << ":\n" << out_dump << "\n";
}