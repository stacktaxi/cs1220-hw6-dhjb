#ifdef TERM_STU
	#include "Vector.cpp"
	#include "Gate.cpp"
	#include "IO.cpp"
	#include "Not.cpp"
	#include "And.cpp"
	#include "Nand.cpp"
	#include "Or.cpp"
	#include "Nor.cpp"
	#include "Xor.cpp"
	#include "Xnor.cpp"
#else
	#include "Vector.h"
	#include "Gate.h"
	#include "IO.h"
	#include "Not.h"
	#include "And.h"
	#include "Nand.h"
	#include "Or.h"
	#include "Nor.h"
	#include "Xor.h"
	#include "Xnor.h"
#endif

#ifdef TERM_INAL
	int main(int argc, char **argv) {
		Vector vector = Vector(argv[1], argv[2]);
		vector.clock();
	}
#else
	#ifdef TERM_STU
		#include "App.cpp"
	#else
		#include "App.h"
	#endif
#endif