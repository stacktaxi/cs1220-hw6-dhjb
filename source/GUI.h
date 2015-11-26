#pragma once

#include <cstdlib>
#include <ctime>
#include <wx/wx.h>

#include "Gate.h"
#include "Scope.h"

enum {
    // ID_OPEN = 1
};

class MainWindow: public wxFrame {
    std::vector<Scope*> scopes;
    wxFlexGridSizer *scopeGrid;
    Vector *vector;

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    // void OnOpen(wxCommandEvent &event); 
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
