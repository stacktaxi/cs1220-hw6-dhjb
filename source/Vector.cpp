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

	in_a->dump();
	printTimeline();
	in_b->dump();
	printTimeline();
	out->dump();
	printTimeline();
}

void Vector::printTimeline() {
	for(int i = 0; i < current_time; ++i) {
		if(i % 5 == 0) {
			std::cout << i;
		}
		else {
			std::cout << " ";
		}
	}
	std::cout << "\n";
}

unsigned Vector::getCurrentTime() {
	return current_time;
}

// Called if the circuit needs more ticks in order to run all of its states.
void Vector::continueRunning() {
	continue_running = true;
}