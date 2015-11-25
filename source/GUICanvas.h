#pragma once

#include <wx/wx.h>

class GUICanvas: public wxPanel {
    DECLARE_EVENT_TABLE();

    public:
        GUICanvas(wxFrame *parent);
        
        void PaintEvent(wxPaintEvent &event);
        void PaintNow();
        void Render(wxDC &dc);
};
