#include "Scope.h"

Scope::Scope(wxFrame* parent, IO *source) 
: GUICanvas(parent), source(source) {
    SetBackgroundColour(*wxWHITE);
}

void Scope::Tick() {
    history.push_back(source->getValue());
}

void Scope::Render(wxDC &dc) {
    // @TESTING
    unsigned true_height = 5;
    unsigned false_height = GetClientSize().GetHeight() - 5;

    if(history.size() == 0)
        return;

    for(unsigned historyPos = 0; historyPos < history.size(); historyPos++) {
        unsigned xpos = historyPos * STEP_WIDTH;
        if(historyPos > 0
            && history[historyPos] != history[historyPos - 1]) {
            dc.DrawLine(xpos, true_height,
                        xpos, false_height);
        }

        if(history[historyPos] == 1) {
            dc.DrawLine(xpos, true_height,
                        xpos + STEP_WIDTH, true_height);
        }
        else if(history[historyPos] == 0) {
            dc.DrawLine(xpos, false_height,
                        xpos + STEP_WIDTH, false_height);
        }
        else {
            dc.SetBrush(wxBrush(*wxBLACK));
            dc.DrawRectangle(xpos, 5,
                             STEP_WIDTH, GetClientSize().GetHeight() - 10);
        }
    }
}

std::string Scope::GetLabel() { return source->getName(); }
