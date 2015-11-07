#include "Vector.h"
#include "IO.h"

Vector::Vector() {
	in_a = new IO("A");
	in_b = new IO("B");
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