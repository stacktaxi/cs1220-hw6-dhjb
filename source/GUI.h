#pragma once

#include <wx/wx.h>

#include "Scope.h"

class SimTimer: public wxTimer {
    Scope *scope;

    public:
        SimTimer(Scope *scope);
        void Notify(); // called every time the timer ticks
        void Start();
};

class MainWindow: public wxFrame {
    Scope *scope;
    SimTimer *timer;

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    DECLARE_EVENT_TABLE();
 
    public:
        MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
        ~MainWindow();
};
