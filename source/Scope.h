#pragma once 

#include <string>
#include <vector>
#include <wx/wx.h>

#include "Gate.h"
#include "IO.h"
#include "GUICanvas.h"

const unsigned STEP_WIDTH = 20;

class Scope: public GUICanvas {
    std::vector<TriState> history;
    IO *source;

    public:
        Scope(wxFrame* parent, IO *source);
       
        void Tick();
        void Render(wxDC &dc);
        std::string GetLabel();
};
