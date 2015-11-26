#pragma once

#include <cstdlib>
#include <ctime>
#include <wx/wx.h>

#include "Gate.h"
#include "Scope.h"

class MainWindow: public wxFrame {
    Scope *scope;

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    DECLARE_EVENT_TABLE();
 
    public:
        MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
        ~MainWindow();

        void Tick();
};
