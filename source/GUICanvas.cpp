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
}
