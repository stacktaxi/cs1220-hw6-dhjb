#include "ScopeTimeline.h"

ScopeTimeline::ScopeTimeline(wxFrame* parent, Vector *vector) 
: GUICanvas(parent), vector(vector) {
    SetBackgroundColour(*wxWHITE);
}

void ScopeTimeline::Render(wxDC &dc) {
    int current_time = vector->getCurrentTime();
    int x_pos = GetClientSize().GetWidth();
    int height = GetClientSize().GetHeight();

    // Align time with time gap
    current_time -= current_time % TIME_GAP;
    x_pos -= (current_time % TIME_GAP) * STEP_WIDTH;

    while(x_pos >= 0 && current_time >= 0) {
        dc.DrawText(std::to_string(current_time), x_pos, 5);

        current_time -= TIME_GAP;
        x_pos -= TIME_GAP * STEP_WIDTH;
    }
}
