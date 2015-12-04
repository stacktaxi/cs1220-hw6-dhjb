// Abstract GUI element for drawing stuff

#pragma once

#include <wx/wx.h>

class GUICanvas: public wxPanel {
    DECLARE_EVENT_TABLE();

    public:
        GUICanvas(wxFrame *parent);
        
        void PaintEvent(wxPaintEvent &event);
        virtual void Render(wxDC &dc) = 0;
};
