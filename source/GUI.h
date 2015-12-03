#pragma once

#include <cstdlib>
#include <ctime>
#include <wx/wx.h>

#include "Gate.h"
#include "Scope.h"
#include "ScopeTimeline.h"

class MainWindow: public wxFrame {
    Vector *vector; 
    std::vector<Scope*> scopes;
    // ScopeTimeline *timeline;
    wxFlexGridSizer *scopeGrid;

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    //void OnResize(wxSizeEvent &event);
    DECLARE_EVENT_TABLE();
 
    public:
        MainWindow(
                Vector *vec,
                const wxString& title, 
                const wxPoint& pos, 
                const wxSize& size);
        ~MainWindow();

        void SetVector(Vector *vec);
        void Tick();
};
