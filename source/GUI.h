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
        ScopePane(wxWindow *parent, Vector *vector);
        ~ScopePane();

        void Refresh();
        void Tick();
};

class MainWindow: public wxFrame {
    ScopePane *scopePane;
    Vector *vector;

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    //void OnResize(wxSizeEvent &event);
    DECLARE_EVENT_TABLE();
 
    public:
        MainWindow(
                Vector *vector,
                const wxString& title, 
                const wxPoint& pos, 
                const wxSize& size);
        ~MainWindow();

        void Tick();
};
