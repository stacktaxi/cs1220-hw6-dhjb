#include "Scope.h"

Scope::Scope(wxFrame* parent, IO *source) 
: GUICanvas(parent), source(source) {
    SetBackgroundColour(*wxWHITE);
}

void Scope::Tick() {
    if(history.size() >= HISTORY_LIMIT) {
        history.erase(history.begin(), history.end() - 256);
    }
    history.push_back(source->getValue()); 
}

void Scope::Render(wxDC &dc) {
    // @TESTING
    int historyPos = history.size() - 1;
    int xpos = GetClientSize().GetWidth();
    unsigned true_height = 5;
    unsigned false_height = GetClientSize().GetHeight() - 5;

    while(xpos >= STEP_WIDTH && historyPos >= 0) {
        if(historyPos > 0 
            && history[historyPos] != history[historyPos - 1]) {
            dc.DrawLine(xpos - STEP_WIDTH, true_height, 
                        xpos - STEP_WIDTH, false_height);
        }

        if(history[historyPos] == 1) {
            dc.DrawLine(xpos, true_height, 
                        xpos - STEP_WIDTH, true_height);
        }
        else if(history[historyPos] == 0) {
            dc.DrawLine(xpos, false_height, 
                        xpos - STEP_WIDTH, false_height); 
        }
        else {
            // draw rectangle
            dc.SetBrush(wxBrush(*wxBLACK));
            dc.DrawRectangle(xpos - STEP_WIDTH, 5, 
                             STEP_WIDTH, GetClientSize().GetHeight() - 10);
        } 

        historyPos--;
        xpos -= STEP_WIDTH;
    }
}

std::string Scope::GetLabel() { return source->getName(); }
