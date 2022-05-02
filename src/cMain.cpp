#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(10001,  cMain::onButtonClicked)
    EVT_MENU(wxID_EXIT, cMain::onQuit)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Asthma Counter by ViceroyFaust", wxPoint(30, 30), wxSize(800, 600)) {
    m_menubar = new wxMenuBar;
    m_file = new wxMenu;

    m_menubar->Append(m_file, wxT("&File"));
    m_file->Append(wxID_ANY, wxT("&New"));
    m_file->Append(wxID_ANY, wxT("&Open"));
    m_file->Append(wxID_ANY, wxT("&Save"));
    m_file->AppendSeparator();
    m_file->Append(wxID_EXIT, wxT("&Quit"));
    SetMenuBar(m_menubar);

    m_btn1 = new wxButton(this, 10001, "Click Me", wxPoint(10, 10), wxSize(150, 50));
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
    m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

void cMain::onQuit(wxCommandEvent& evt) {
    Close(true);
}

void cMain::onButtonClicked(wxCommandEvent &evt) {
    wxPuts(wxT("Button Clicked"));
    m_list1->AppendString(m_txt1->GetValue());
    evt.Skip();
}

cMain::~cMain() {}
