#include "Vector.h"
#include "IO.h"

Vector::Vector() {
	in_a = new IO();
	in_b = new IO();
	in_a->addOut(out_a);
	in_b->addOut(out_a);
}

void Vector::tick() {
	if(current_time == 0) {
		in_a->tick();
	}
	else if(current_time == 2) {
		in_b->tick();
	}

	++current_time;
}

unsigned Vector::getCurrentTime() {
	return current_time;
}