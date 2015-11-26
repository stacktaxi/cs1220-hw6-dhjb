#pragma once 

#include <vector>
#include <wx/wx.h>

#include "Gate.h"
#include "IO.h"
#include "GUICanvas.h"

const unsigned STEP_WIDTH = 5;
const unsigned HISTORY_LIMIT = 1024;

class Scope: public GUICanvas {
    // @TESTING
    std::vector<TriState> history;

    public:
        Scope(wxFrame* parent);
       
        void Tick(TriState test);
        void Render(wxDC &dc);
};
