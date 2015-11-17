#include "Vector.h"
#include "IO.h"
#include "And.h"
#include "Not.h"

Vector::Vector() {
	// @TESTING
	in[0] = new IO("A");
	in[1] = new IO("B");
	a = new And(in[0], in[1]);
	n = new Not(a);
	out = new IO("C", n);
	a->addOut(n);
	n->addOut(out);
	in[0]->addOut(a);
	in[1]->addOut(a);
}

void Vector::clock() {
	while(continue_running) {
		continue_running = false;

		in[0]->tick();
		in[1]->tick();

		++current_time;
	}

	in[0]->dump();
	printTimeline();
	in[1]->dump();
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