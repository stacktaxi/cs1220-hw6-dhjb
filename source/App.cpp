#include "App.h"

bool SimApp::OnInit() {
    MainWindow *mainWindow = new MainWindow("Digital Circuit Sim", wxPoint(50, 50), wxSize(640, 480));
    mainWindow->Show(true);
    return true;
}

wxIMPLEMENT_APP(SimApp); 
