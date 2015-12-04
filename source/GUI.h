// Top-level basic GUI class.

#pragma once

#include <cstdlib>
#include <ctime>
#include <wx/wx.h>

#include "Gate.h"
#include "Scope.h"
#include "ScopeTimeline.h"

class ScopePane: public wxScrolledWindow {
    Vector *vector;

    ScopeTimeline *timeline;
    std::vector<Scope*> scopes;
    wxFlexGridSizer *scopeGrid; 

    public:
        ScopePane(wxWindow*, Vector*);
        ~ScopePane();

        // Updates the timeline and scopes.
        void Refresh();
        void Tick();
};

class MainWindow: public wxFrame {
    ScopePane *scopePane;
    Vector *vector;

    void OnClose(wxCloseEvent&);
    void OnExit(wxCommandEvent&);
    DECLARE_EVENT_TABLE();
 
    public:
        MainWindow(Vector*, const wxString&, const wxPoint&, const wxSize&);
        ~MainWindow();

        // Updates the scope pane.
        void Tick();
};
