#include "App.h"

SimTimer::SimTimer(Vector *vector, MainWindow *mainWin)
: wxTimer(), vector(vector), mainWin(mainWin) {}

void SimTimer::Notify() {
    if(vector->isRunning() && vector->getCurrentTime() < MAX_RUNNING_TIME) {
        vector->tick();
        vector->update();
    }
    mainWin->Tick();
}

void SimTimer::Start() { 
    wxTimer::Start(10); 
}

SimApp::~SimApp() {
    delete vector;
    delete timer;
}

bool SimApp::OnInit() {
    if(argc < 3) {
        std::cout << "Usage: " << std::string(wxApp::argv[0]) << " circuit_file vector_file" << std::endl;
        return false;
    }

    vector = new Vector(std::string(wxApp::argv[1]), std::string(wxApp::argv[2]));
    
    MainWindow *mainWindow 
        = new MainWindow(
                vector, 
                "Digital Circuit Sim", 
                wxPoint(50, 50), 
                wxSize(640, 480));

    timer = new SimTimer(vector, mainWindow);
    mainWindow->Show(true);
    timer->Start(); 

    return true;
}

wxIMPLEMENT_APP(SimApp); 
