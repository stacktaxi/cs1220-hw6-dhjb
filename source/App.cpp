#include "App.h"

// Timer code is largely borrowed from the wiki

SimTimer::SimTimer(Vector *vector, MainWindow *mainWin)
: wxTimer(), vector(vector), mainWin(mainWin) {}

void SimTimer::Notify() {
    if(vector->isRunning())
        vector->tick();
    mainWin->Tick();
}

void SimTimer::Start() { wxTimer::Start(10); }

SimApp::~SimApp() {
    delete vector;
}

bool SimApp::OnInit() {
    if(argc < 3)
        return false;

    vector = new Vector(std::string(wxApp::argv[1]), std::string(wxApp::argv[2]));
    
    MainWindow *mainWindow = new MainWindow(vector, "Digital Circuit Sim", wxPoint(50, 50), wxSize(640, 480));
    // mainWindow->SetMinSize(wxSize(480, 320));
    timer = new SimTimer(vector, mainWindow);
    mainWindow->Show(true);
    timer->Start(); 

    return true;
}

wxIMPLEMENT_APP(SimApp); 
