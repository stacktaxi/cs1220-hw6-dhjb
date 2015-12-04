#include "GUICanvas.h"

// Connects the canvas with paint events.
wxBEGIN_EVENT_TABLE(GUICanvas, wxPanel)
    EVT_PAINT(GUICanvas::PaintEvent)
wxEND_EVENT_TABLE()

GUICanvas::GUICanvas(wxFrame *parent)
: wxPanel(parent) {}

void GUICanvas::PaintEvent(wxPaintEvent &event) {
    wxPaintDC dc(this);
    Render(dc);
}
