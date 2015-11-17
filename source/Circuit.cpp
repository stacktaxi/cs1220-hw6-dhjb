#include "Circuit.h"

Circuit::Circuit() {
}

Circuit::~Circuit() {
    for(int i = 0; i < ins.size(); i++)
        delete ins[i];
    for(int i = 0; i < outs.size(); i++)
        delete outs[i];
    for(int i = 0; i < gates.size(); i++)
        delete gates[i];
}

/*
 * Splits a string by delim and stores the results in tokens.
 * I'm certain there are more efficient ways to do this, I just crapped this out
 * for speed's sake.
 */
void tokenizeStr(std::string s, std::vector<std::string> &tokens, char delim) {
    tokens.clear();
    std::string substring = s;
    size_t pos = substring.find_first_of(delim);

    // Keep splitting off parts of string until delim is no longer found.
    while(pos != std::string::npos) {
        tokens.push_back(substring.substr(0, pos));
        substring = substring.substr(pos + 1); 
        pos = substring.find_first_of(delim);
    }

    tokens.push_back(substring);
} 

void Circuit::loadFile(std::string filepath) {
    std::ifstream infile(filepath.c_str(), std::ifstream::in); 
    std::string line;
    std::vector<std::string> tokens;

    while(!infile.eof()) {
        getline(infile, line);
        tokenizeStr(line, tokens, ' ');  
               
        /*
         * @CONSIDER -- could we keep the wire definitions within this function?
         * The wire number is a part of the specification for the circuit file
         * format. Given our design, we could keep those numbers as defined in the
         * circuit file within this function, since the Gate class will have no need
         * of it.
         */
        if(tokens[0] == "CIRCUIT") {
            header = tokens[1];
        }
        else if(tokens[0] == "INPUT") {
        } 
        else if(tokens[0] == "OUTPUT") {
            // ...
        }
        else if(tokens[0] == "GATE") {
            if(tokens[1] == "NOT" || tokens[1] == "INVERTER") {
                // ...
            }
            else if(tokens[1] == "AND") {
                // ...
            }
            else if(tokens[1] == "OR") {
            }
            else if(tokens[1] == "XOR") {
            }
            else if(tokens[1] == "NAND") {
            }
            else if(tokens[1] == "NOR") {
            }
            else if(tokens[1] == "XNOR") {
            }
        } 
    }
    
    infile.close();
 
}
