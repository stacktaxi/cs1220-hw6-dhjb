#include "GUICanvas.h"

wxBEGIN_EVENT_TABLE(GUICanvas, wxPanel)
    EVT_PAINT(GUICanvas::PaintEvent)
wxEND_EVENT_TABLE()

GUICanvas::GUICanvas(wxFrame *parent)
: wxPanel(parent) {}

void GUICanvas::PaintEvent(wxPaintEvent &event) {
    wxPaintDC dc(this);
    Render(dc);
}

void GUICanvas::PaintNow() {
    wxClientDC dc(this);
    Render(dc);
}

void GUICanvas::Render(wxDC &dc) {
    static int y = 0;
    static int y_speed = 2;

    y += y_speed;
    if(y < 0)
        y_speed = 2;
    else if(y > 100)
        y_speed = -2;

    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    dc.DrawText("Testing", 40, y);
}
