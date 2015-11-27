#include "GUI.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_CLOSE(MainWindow::OnClose)
    // EVT_MENU(ID_OPEN, MainWindow::OnOpen)
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
wxEND_EVENT_TABLE()

MainWindow::MainWindow
(Vector *vec, const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size), vector(vec) {
    // menu bar
    wxMenu *fileMenu = new wxMenu;
    // fileMenu->Append(ID_OPEN, "&Open");
    fileMenu->Append(wxID_EXIT); 

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");

    SetMenuBar(menuBar);

    // @TESTING
    // Replace with accessors to vector class.
    vector->connectScopes(this, scopes);

    scopeGrid = new wxFlexGridSizer(scopes.size(), 2, 0, 0);
    for(int i = 0; i < scopes.size(); i++) {
        scopeGrid->AddGrowableRow(i, 1);
        scopeGrid->Add(new wxStaticText(this, -1, scopes[i]->GetLabel()));
        scopeGrid->Add(scopes[i], 0, wxEXPAND);
    }
    scopeGrid->AddGrowableCol(1,1);

    // set up the sizer
    wxBoxSizer *top = new wxBoxSizer(wxVERTICAL);
    /*
    top->Add(
            new wxStaticText(this, -1, "circuit"),
            1,
            wxEXPAND | wxALL,
            2);
    */
    top->Add(
            scopeGrid,
            1,
            wxEXPAND);
    
    SetSizerAndFit(top);

    // status bar
    // this seems cheap, but it's also very simple. I think we should stick with this
    // unless SetStatusText() becomes annoying to use.
    CreateStatusBar();
    SetStatusText("nonfunctional"); 
}

MainWindow::~MainWindow() { 
    for(Scope* scope : scopes)
        delete scope;
}

void MainWindow::SetVector(Vector *vec) { vector = vec; }

void MainWindow::Tick() {
    for(Scope *scope : scopes) {
        scope->Tick();
        scope->Refresh();
    }
}


void MainWindow::OnClose(wxCloseEvent &event) {
    event.Skip();
}

void MainWindow::OnExit(wxCommandEvent& event) { Close(true); }


/*
void MainWindow::OnOpen(wxCommandEvent& event) {
}
*/

