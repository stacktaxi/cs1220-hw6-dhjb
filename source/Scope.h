// Reads from a source input or output and draws the values to a scope

#pragma once 

#include <string>
#include <vector>
#include <wx/wx.h>

#include "Gate.h"
#include "IO.h"
#include "Vector.h"
#include "GUICanvas.h"

const unsigned STEP_WIDTH = 50;

class Scope: public GUICanvas {
    std::vector<TriState> history;
    IO *source;

    public:
        Scope(wxFrame* parent, IO *source);
       
        void Tick();
        void Render(wxDC &dc);
        std::string GetLabel();
};
