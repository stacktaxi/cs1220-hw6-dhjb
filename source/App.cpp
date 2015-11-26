#include "App.h"

// Timer code is largely borrowed from the wiki

SimTimer::SimTimer(MainWindow *mainWin)
: wxTimer(), mainWin(mainWin) {}

void SimTimer::Notify() {
    mainWin->Tick();
}

void SimTimer::Start() { wxTimer::Start(10); }

/**********************************/

SimApp::~SimApp() {
    delete vector;
}

bool SimApp::OnInit() {
    if(argc < 3)
        return false;

    vector = new Vector(std::string(wxApp::argv[1]), std::string(wxApp::argv[2]));
	// vector = new Vector("./resources/sample_circuit", "./resources/sample_vector");
	 // vector->clock();


    
    MainWindow *mainWindow = new MainWindow("Digital Circuit Sim", wxPoint(50, 50), wxSize(640, 480));
    timer = new SimTimer(mainWindow);
    mainWindow->Show(true);
    timer->Start(); 

    return true;
}

wxIMPLEMENT_APP(SimApp); 
