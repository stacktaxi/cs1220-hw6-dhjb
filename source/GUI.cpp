#include "GUI.h"

ScopePane::ScopePane(wxWindow *parent, Vector *vector)
: wxScrolledWindow(parent), vector(vector){
    vector->connectScopes((wxFrame *)this, scopes);
    timeline = new ScopeTimeline((wxFrame*) this, vector);

    scopeGrid = new wxFlexGridSizer(scopes.size() + 1, 2, 5, 5);
    scopeGrid->Add(new wxStaticText(this, -1, "Time"));
    scopeGrid->Add(timeline, 0, wxEXPAND);
    for(int i = 0; i < scopes.size(); i++) {
        scopeGrid->AddGrowableRow(i + 1, 1);
        scopeGrid->Add(new wxStaticText(this, -1, scopes[i]->GetLabel()));
        scopeGrid->Add(scopes[i], 0, wxEXPAND);
    }
    scopeGrid->AddGrowableCol(1,1);

    // set up the sizer
    wxBoxSizer *top = new wxBoxSizer(wxVERTICAL);
    top->Add(
            scopeGrid,
            1,
            wxEXPAND);
    
    SetSizer(top);
    FitInside();
    SetScrollRate(5, 5);
}

ScopePane::~ScopePane() {
    for(Scope *scope : scopes)
        delete scope;
    delete timeline;
}

void ScopePane::Refresh() {
    for(Scope *scope : scopes)
        scope->Refresh();
    timeline->Refresh();
    FitInside();
}

void ScopePane::Tick() {
    if(vector->isRunning()) {
        for(Scope *scope : scopes)
            scope->Tick();
    } 
    Refresh();
}

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_CLOSE(MainWindow::OnClose)
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
    // EVT_SIZE(MainWindow::OnResize)
wxEND_EVENT_TABLE()

MainWindow::MainWindow
(Vector *vector, const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size) {
    // menu bar
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT); 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    SetMenuBar(menuBar); 

    scopePane = new ScopePane(this, vector);

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(
            scopePane,
            1,
            wxEXPAND);
    SetSizer(sizer);

    SetTitle(vector->getName());
}

MainWindow::~MainWindow() {
    delete scopePane;
}


void MainWindow::Tick() {
    scopePane->Tick();
}

void MainWindow::OnClose(wxCloseEvent &event) { event.Skip(); }

void MainWindow::OnExit(wxCommandEvent &event) { Close(true); }


/* void MainWindow::OnResize(wxSizeEvent &event) {
    for(Scope *scope : scopes) {
        scope->Refresh();
    }
} */

