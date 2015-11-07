#include "Vector.h"
#include "IO.h"
#include "And.h"

Vector::Vector() {
	in_a = new IO("A");
	in_b = new IO("B");
	a = new And(in_a, in_b);
	out = new IO("C", a);
	a->addOut(out);
	in_a->addOut(a);
	in_b->addOut(a);
}

void Vector::clock() {
	while(continue_running) {
		continue_running = false;

		in_a->tick();
		in_b->tick();

		++current_time;
	}
}

unsigned Vector::getCurrentTime() {
	return current_time;
}

// Called if the circuit needs more ticks in order to run all of its states.
void Vector::continueRunning() {
	continue_running = true;
}