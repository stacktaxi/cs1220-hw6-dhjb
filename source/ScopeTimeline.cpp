#include "ScopeTimeline.h"

ScopeTimeline::ScopeTimeline(wxFrame* parent, Vector *vector) 
: GUICanvas(parent), vector(vector) {
    SetBackgroundColour(*wxWHITE);
}

void ScopeTimeline::Render(wxDC &dc) {
    for(unsigned time = 0; time <= vector->getCurrentTime(); time++) {
        if(!(time % TIME_GAP)) {
            if(STEP_WIDTH > 20 && time > 0) {
                if(time < 10)
                    dc.DrawText(std::to_string(time), time * STEP_WIDTH - 8, 0);
                else 
                    dc.DrawText(std::to_string(time), time * STEP_WIDTH - 17, 0);
                dc.DrawLine(time * STEP_WIDTH, 0,
                            time * STEP_WIDTH, GetClientSize().GetHeight());
            }
            else 
                dc.DrawText(std::to_string(time), time * STEP_WIDTH, 0);
        }
        else
            dc.DrawLine(time * STEP_WIDTH, 0, 
                        time * STEP_WIDTH, GetClientSize().GetHeight());
    } 

    this->SetMinClientSize(wxSize(vector->getCurrentTime() * STEP_WIDTH, 10));
}
