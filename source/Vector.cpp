#include "Vector.h"
#include "IO.h"
#include "Not.h"
#include "And.h"
#include "Nand.h"
#include "Or.h"
#include "Nor.h"
#include "Xor.h"
#include "Xnor.h"


void tokenizeStr(std::string s, std::vector<std::string> &tokens, char delim) {
    tokens.clear();
    std::string substring = "";
    size_t pos = 0;

    // Keep splitting off parts of string until delim is no longer found.
    for(; pos < s.length(); pos++) {
        if(s[pos] == ' ') {
            if(!substring.empty()) {
                tokens.push_back(substring);
                substring = "";
            }
        }
        else {
            substring.push_back(s[pos]);
        }
    }

    if(!substring.empty())
        tokens.push_back(substring);
}

Vector::Vector(std::string circuit_path, std::string vector_path) {
    std::ifstream infile(circuit_path.c_str(), std::ifstream::in);
    std::string line;
    std::vector<std::string> tokens;

    std::map<unsigned, Wire> wires;

    while(!infile.eof()) {
        getline(infile, line);
        tokenizeStr(line, tokens, ' ');

        if(tokens[0] == "CIRCUIT") {
            name = tokens[1];
        }
        else if(tokens[0] == "INPUT") {
            IO *input = new IO(this, 0, tokens[1]);
            wires[std::stoi(tokens[2])].in = input;
            inputs.push_back(input);
        }
        else if(tokens[0] == "OUTPUT") {
            IO *output = new IO(this, 0, tokens[1]);
            wires[std::stoi(tokens[2])].outs.push_back(output);
            outputs.push_back(output);
        }
        else if(tokens[0] == "NOT" || tokens[0] == "INVERTER") {
        	Not *gate = new Not(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].in = gate;
            other.push_back(gate);
        }
        else if(tokens[0] == "AND") {
        	And *gate = new And(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].outs.push_back(gate);
            wires[std::stoi(tokens[4])].in = gate;
            other.push_back(gate);
        }
        else if(tokens[0] == "OR") {
        	Or *gate = new Or(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].outs.push_back(gate);
            wires[std::stoi(tokens[4])].in = gate;
            other.push_back(gate);
        }
        else if(tokens[0] == "XOR") {
        	Xor *gate = new Xor(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].outs.push_back(gate);
            wires[std::stoi(tokens[4])].in = gate;
            other.push_back(gate);
        }
        else if(tokens[0] == "NAND") {
        	Nand *gate = new Nand(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].outs.push_back(gate);
            wires[std::stoi(tokens[4])].in = gate;
            other.push_back(gate);
        }
        else if(tokens[0] == "NOR") {
        	Nor *gate = new Nor(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].outs.push_back(gate);
            wires[std::stoi(tokens[4])].in = gate;
            other.push_back(gate);
        }
        else if(tokens[0] == "XNOR") {
        	Xnor *gate = new Xnor(this, std::stoi(tokens[1]));
            wires[std::stoi(tokens[2])].outs.push_back(gate);
            wires[std::stoi(tokens[3])].outs.push_back(gate);
            wires[std::stoi(tokens[4])].in = gate;
            other.push_back(gate);
        }
    }

    infile.close();

    for(auto const &entry : wires) {
    	entry.second.in->setOutputs(entry.second.outs);

    	for(Gate *out : entry.second.outs) {
    		out->setInput(entry.second.in);
    	}
	}

	infile.open(vector_path);

	while(!infile.eof()) {
        getline(infile, line);

        if(line.empty()) {
        	continue;
        }

        tokenizeStr(line, tokens, ' ');
        if(tokens[0] != "INPUT") {
        	continue;
        }
        else {
        	for(IO *in : inputs) {
        		if(in->getName() == tokens[1]) {
        			ValueAtTime t = {(unsigned) std::stoi(tokens[2]), tokens[3] == "X" ? X : std::stoi(tokens[3])};
        			in->addValue(t);
        			break;
        		}
        	}
        }
    }
}

void Vector::clock() {
	// std::cout << "How many nanoseconds should be our max?\n";

	// std::cin >> max;

	while(continue_running && current_time <= MAX_RUNNING_TIME) {
		tick();
        update();
	}

	for(IO *in : inputs) {
		in->dump();
		printTimeline();
	}

	for(IO *out : outputs) {
		out->dump();
		printTimeline();
	}
}

void Vector::tick() {
	continue_running = false;

	for(IO *in : inputs) {
		in->tick();
	}

    /*
	for(Gate *gate : other) {
		if(gate->getCurrentTime() < current_time || gate->getCurrentTime() == UINT_MAX) {
			gate->tick();
		}
	}
    */

#ifdef TERM_DEBUG
    printf("Tick finished, vector time %d\n", current_time);
#endif 

	++current_time;
}

void Vector::update() {
    for(IO *in : inputs) {
        in->update();
    }

    /*
    for(Gate *gate : other) {
        gate->update();
    }
    */
}

void Vector::printTimeline() {
	for(unsigned i = 0; i < current_time; ++i) {
		if(i % 5 == 0) {
			std::cout << i;
		}
		else {
			std::cout << " ";
		}
	}
	std::cout << "\n";
}

void Vector::continueRunning() { continue_running = true; } 

bool Vector::isRunning() { return continue_running; } 
unsigned Vector::getCurrentTime() { return current_time; }
std::string Vector::getName() { return name; }

#ifndef TERM_INAL
void Vector::connectScopes(wxFrame *win, std::vector<Scope*> &scopes) {
	for(IO *input : inputs)
	    scopes.push_back(new Scope(win, input));
	for(IO *output: outputs)
	    scopes.push_back(new Scope(win, output));
}
#endif
