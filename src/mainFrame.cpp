#include "mainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(10001,  MainFrame::onButtonClicked)
    EVT_MENU(wxID_EXIT, MainFrame::onQuit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Asthma Counter by ViceroyFaust", wxPoint(30, 30), wxSize(300, 400)), m_doses(120) {
    m_menubar = new wxMenuBar;
    m_file = new wxMenu;

    m_menubar->Append(m_file, wxT("&File"));
    m_file->Append(wxID_ANY, wxT("&New"));
    m_file->Append(wxID_ANY, wxT("&Open"));
    m_file->Append(wxID_ANY, wxT("&Save"));
    m_file->AppendSeparator();
    m_file->Append(wxID_EXIT, wxT("&Quit"));
    SetMenuBar(m_menubar);

    wxString strDoseCounter = wxString("Doses Left: ").append(wxString::Format("%i", m_doses));
    m_counterLabel =  new wxStaticText(this, wxID_ANY, strDoseCounter, wxPoint(10, 10));
    wxString strHistLabel("Recent History:");
    m_histLabel = new wxStaticText(this, wxID_ANY, strHistLabel, wxPoint(10, 30));

    m_histList = new wxListBox(this, wxID_ANY, wxPoint(10, 50), wxSize(200, 100));

    m_decButton = new wxButton(this, 10001, "Take Dose", wxPoint(10, 160), wxSize(150, 50));
    m_undoButton = new wxButton(this, wxID_ANY, "Undo", wxPoint(10, 220), wxSize(150, 50));

}

void MainFrame::onQuit(wxCommandEvent& evt) {
    Close(true);
}

void MainFrame::onButtonClicked(wxCommandEvent &evt) {
    wxPuts(wxT("Button Clicked"));
    --m_doses;
    m_counterLabel->SetLabel(wxString("Doses Left: ").append(wxString::Format("%i", m_doses)));
    evt.Skip();
}

MainFrame::~MainFrame() {}
