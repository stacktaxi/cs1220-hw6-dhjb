#include "GUI.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
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

    // set up the sizer
    wxBoxSizer *top = new wxBoxSizer(wxVERTICAL);
    top->Add(
            new wxStaticText(this, -1, "circuit"),
            1,
            wxEXPAND | wxALL,
            2);
    top->Add(
            new wxStaticText(this, -1, "scope"),
            1,
            wxEXPAND | wxALL,
            2);
    
    SetSizerAndFit(top);

    // status bar
    // this seems cheap, but it's also very simple. I think we should stick with this
    // unless SetStatusText() becomes annoying to use.
    CreateStatusBar();
    SetStatusText("nonfunctional");
}

void MainWindow::OnExit(wxCommandEvent& event) { Close(true); }
