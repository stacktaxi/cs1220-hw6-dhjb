#pragma once

#include <wx/wx.h>

#include "GUI.h"
#include "Vector.h"

class SimApp: public wxApp {
    Vector *vector;
    public:
        ~SimApp();

        virtual bool OnInit();
};
