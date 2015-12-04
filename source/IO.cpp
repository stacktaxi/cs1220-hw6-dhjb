#include "IO.h"

IO::IO(Vector *v, unsigned _delay, std::string _name) : Gate(v, _delay) {
	name = _name;
}

TriState IO::recompute() {
	TriState v;

#ifdef TERM_DEBUG
    printf("IO  %s ", name.c_str());
#endif

	if(in[0]) {
		// We are an output. This means that we get our value from an input.
		v = in[0]->getValue();
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

std::string IO::getName() {
	return name;
}

void IO::addValue(ValueAtTime value) {
	future_values.push(value);
}

bool IO::isRunning() { return my_vector->isRunning(); }
