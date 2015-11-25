#include "App.h"

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
    mainWindow->Show(true);
    return true;
}

wxIMPLEMENT_APP(SimApp); 
