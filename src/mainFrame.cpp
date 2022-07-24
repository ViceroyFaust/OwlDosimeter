#include "mainFrame.h"
#include <wx/textfile.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(doseButtonId,  MainFrame::onDoseButtonClicked)
    EVT_MENU(wxID_EXIT, MainFrame::onQuit)
    EVT_MENU(wxID_SAVEAS, MainFrame::onSaveAs)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Dose Counter", wxPoint(30, 30), wxSize(300, 400)), m_doses(120) {
    m_menubar = new wxMenuBar;
    m_file = new wxMenu;

    m_menubar->Append(m_file, wxT("&File"));
    m_file->Append(wxID_ANY, wxT("&New"));
    m_file->Append(wxID_ANY, wxT("&Open"));
    m_file->Append(wxID_ANY, wxT("&Save"));
    m_file->Append(wxID_SAVEAS, wxT("&Save As"));
    m_file->AppendSeparator();
    m_file->Append(wxID_EXIT, wxT("&Quit"));
    SetMenuBar(m_menubar);

    wxString strDoseCounter = wxString("Doses Left: ").append(wxString::Format("%i", m_doses));
    m_counterLabel =  new wxStaticText(this, wxID_ANY, strDoseCounter, wxDefaultPosition);

    wxString strHistLabel("Recent History:");
    m_histLabel = new wxStaticText(this, wxID_ANY, strHistLabel, wxDefaultPosition);

    m_histList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(400, 200));

    m_doseButton = new wxButton(this, doseButtonId, "Take Dose", wxDefaultPosition, wxSize(150, 50));
    m_undoButton = new wxButton(this, undoButtonId, "Undo", wxDefaultPosition, wxSize(150, 50));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_counterLabel, 0, wxALL, 10);
    sizer->Add(m_histLabel, 0, wxALL, 10);
    sizer->Add(m_histList, 1, wxEXPAND | wxALL, 10);
    sizer->Add(m_doseButton, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->Add(m_undoButton, 0, wxALIGN_CENTER | wxALL, 10);

    this->SetSizerAndFit(sizer);
}

void MainFrame::onQuit(wxCommandEvent& evt) {
    Close(true);
}

void MainFrame::onSaveAs(wxCommandEvent& evt) {
    wxFileDialog* fd = new wxFileDialog
    (this, "Choose File", "", "DosimeterLog.txt", "Text Files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	// Creates a "open file" dialog
	if (fd->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		wxString CurrentDocPath = fd->GetPath();
		// Sets our current document to the file the user selected
		wxArrayString list = m_histList->GetStrings();
        wxTextFile file(CurrentDocPath);
        file.Create();

        size_t count = list.Count();
        for( size_t i = 0 ; i < count ; ++i )
            file.AddLine( list[ i ] );

        file.Write();
        file.Close();
	}

	// Clean up after ourselves
	fd->Destroy();
}

void MainFrame::onDoseButtonClicked(wxCommandEvent &evt) {
    wxPuts(wxT("Button Clicked"));
    --m_doses;
    m_counterLabel->SetLabel(wxString("Doses Left: ").append(wxString::Format("%i", m_doses)));
    wxDateTime now = wxDateTime::Now();
    wxString doseDateTime = now.Format("%F %R");
    m_histList->AppendAndEnsureVisible(doseDateTime);
    evt.Skip();
}

MainFrame::~MainFrame() {}
