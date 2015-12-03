#pragma once

#include <wx/wx.h>

#include "GUICanvas.h"
#include "Scope.h"
#include "Vector.h"

const unsigned TIME_GAP = 5;

class ScopeTimeline: public GUICanvas {
    Vector *vector; 
    
    public:
        ScopeTimeline(wxFrame* parent, Vector *vector);

        void Render(wxDC &dc);
};
