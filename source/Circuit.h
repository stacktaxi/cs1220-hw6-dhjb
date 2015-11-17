#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "IO.h"
#include "Gate.h"

class Circuit {
    private:
        // Probably replace these with maps, too tired to do it now
        std::vector<IO*> ins; 
        std::vector<IO*> outs;
        std::vector<Gate*> gates;

        std::string header = "";

    public:
        Circuit();
        ~Circuit();

        void loadFile(std::string filepath);
};
