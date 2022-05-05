#include "cMain.h"

#include <string>

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(10001,  cMain::onButtonClicked)
    EVT_MENU(wxID_EXIT, cMain::onQuit)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Asthma Counter by ViceroyFaust", wxPoint(30, 30), wxSize(800, 600)), m_doses(120) {
    m_menubar = new wxMenuBar;
    m_file = new wxMenu;

    m_menubar->Append(m_file, wxT("&File"));
    m_file->Append(wxID_ANY, wxT("&New"));
    m_file->Append(wxID_ANY, wxT("&Open"));
    m_file->Append(wxID_ANY, wxT("&Save"));
    m_file->AppendSeparator();
    m_file->Append(wxID_EXIT, wxT("&Quit"));
    SetMenuBar(m_menubar);

    wxString strMessage = wxString("Doses Left: ").append(wxString::Format("%i", m_doses));
    m_btn1 = new wxButton(this, 10001, "Click Me", wxPoint(10, 10), wxSize(150, 50));
    m_text =  new wxStaticText(this, wxID_ANY, wxString(strMessage), wxPoint(10, 60));
}

void cMain::onQuit(wxCommandEvent& evt) {
    Close(true);
}

void cMain::onButtonClicked(wxCommandEvent &evt) {
    wxPuts(wxT("Button Clicked"));
    --m_doses;
    m_text->SetLabel(wxString("Doses Left: ").append(wxString::Format("%i", m_doses)));
    evt.Skip();
}

cMain::~cMain() {}
