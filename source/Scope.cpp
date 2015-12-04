#include "Scope.h"

Scope::Scope(wxFrame* parent, IO *source) 
: GUICanvas(parent), source(source) {
    SetBackgroundColour(*wxWHITE);
}

void Scope::Tick() {
    if(source->isRunning() && source->getCurrentTime() <= MAX_RUNNING_TIME)
        history.push_back(source->getValue());
}

void Scope::Render(wxDC &dc) {
    const unsigned true_height = 5;
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
        else {
            for(unsigned y = 5; y < GetClientSize().GetHeight(); y += 10)
                dc.DrawPoint(xpos, y);
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

    this->SetMinClientSize(wxSize(history.size() * STEP_WIDTH, 50));
}

std::string Scope::GetLabel() { return source->getName(); }
