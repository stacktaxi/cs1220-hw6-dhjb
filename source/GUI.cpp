#include "GUI.h"

// Timer code is largely borrowed from the wiki:

SimTimer::SimTimer(Scope *scope)
: wxTimer(), scope(scope) {}

void SimTimer::Notify() { scope->Refresh(); }

void SimTimer::Start() { wxTimer::Start(5); }

/**************------------------*******************/

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_CLOSE(MainWindow::OnClose) 
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
wxEND_EVENT_TABLE()

MainWindow::MainWindow
(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size) {
    // menu bar
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT); 

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");

    SetMenuBar(menuBar);

    scope = new Scope(this);

    // set up the sizer
    wxBoxSizer *top = new wxBoxSizer(wxVERTICAL);
    top->Add(
            new wxStaticText(this, -1, "circuit"),
            1,
            wxEXPAND | wxALL,
            2);
    top->Add(
            scope,
            1,
            wxEXPAND | wxALL,
            2);
    
    SetSizerAndFit(top);

    // status bar
    // this seems cheap, but it's also very simple. I think we should stick with this
    // unless SetStatusText() becomes annoying to use.
    CreateStatusBar();
    SetStatusText("nonfunctional"); 

    timer = new SimTimer(scope);
    Show();
    timer->Start();
}

MainWindow::~MainWindow() { 
    delete timer;
}


void MainWindow::OnClose(wxCloseEvent &event) {
    timer->Stop();
    event.Skip();
}

void MainWindow::OnExit(wxCommandEvent& event) { Close(true); }
