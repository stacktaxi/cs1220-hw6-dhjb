#pragma once

#include <wx/wx.h>

#include "GUI.h"
#include "Vector.h"

class SimTimer: public wxTimer {
    MainWindow *mainWin;

    public:
        SimTimer(MainWindow *mainWin);
        void Notify(); // called every time the timer ticks
        void Start();
}; 

class SimApp: public wxApp {
    Vector *vector;
    SimTimer *timer;

    public:
        ~SimApp();

        virtual bool OnInit();
};
