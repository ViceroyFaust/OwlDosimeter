#include "mainFrame.h"
#include <wx/textfile.h>
#include <wx/numdlg.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT, MainFrame::onQuit)
    EVT_MENU(wxID_OPEN, MainFrame::onOpen)
    EVT_MENU(wxID_NEW, MainFrame::onNew)
    EVT_MENU(wxID_SAVE, MainFrame::onSave)
    EVT_MENU(wxID_SAVEAS, MainFrame::onSaveAs)
    EVT_MENU(wxID_UNDO, MainFrame::onUndo)
    EVT_BUTTON(doseButtonId,  MainFrame::onDoseButtonClicked)
    EVT_BUTTON(undoButtonId, MainFrame::onUndo)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Dose Counter", wxPoint(30, 30), wxSize(300, 400)),
        m_doses(0), m_undoHist(0), curDocPath("") {
    m_menubar = new wxMenuBar;
    m_file = new wxMenu;
    m_edit = new wxMenu;

    m_menubar->Append(m_file, wxT("&File"));
    m_file->Append(wxID_NEW, wxT("&New"));
    m_file->Append(wxID_OPEN, wxT("&Open"));
    m_file->Append(wxID_SAVE, wxT("&Save"));
    m_file->Append(wxID_SAVEAS, wxT("&Save As"));
    m_file->AppendSeparator();
    m_file->Append(wxID_EXIT, wxT("&Quit"));

    m_menubar->Append(m_edit, wxT("&Edit"));
    m_edit->Append(wxID_UNDO, wxT("&Undo"));
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

void MainFrame::saveDoses() {
    wxArrayString list = m_histList->GetStrings();
    wxTextFile file(curDocPath);
    file.Create();
    file.AddLine(wxString::Format("%i", m_doses));
    size_t count = list.Count();
    for( size_t i = 0 ; i < count ; ++i )
        file.AddLine( list[ i ] );
    file.Write();
    file.Close();
}

void MainFrame::updateCounter() {
    m_counterLabel->SetLabel(wxString("Doses Left: ").append(wxString::Format("%i", m_doses)));
}

void MainFrame::onQuit(wxCommandEvent& evt) {
    Close(true);
}

void MainFrame::onOpen(wxCommandEvent& evt) {
    wxFileDialog* fd = new wxFileDialog
        (this, "Choose File", "", "", "Text Files (*.txt)|*.txt", wxFD_OPEN);
    if (fd->ShowModal() == wxID_OK) {
        m_histList->Clear();
        wxTextFile file;
        file.Open(fd->GetPath());
        wxString str = file.GetFirstLine();
        long count = 0;
        str.ToLong(&count);
        m_doses = static_cast<int>(count);
        updateCounter();
        for (str = file.GetNextLine();!file.Eof(); str = file.GetNextLine()) {
            m_histList->AppendAndEnsureVisible(str);
        }
        SetTitle(wxString("Dose Counter - ") << fd->GetFilename());
    }
    fd->Destroy();
}

void MainFrame::onNew(wxCommandEvent& evt) {
    wxNumberEntryDialog* dialog = new wxNumberEntryDialog
        (this, "Enter Dose Amount", "Doses:", "New Dosimeter", 0, 0, 1000);
    if (dialog->ShowModal() == wxID_OK) {
        curDocPath = "";
        m_doses = dialog->GetValue();
        updateCounter();
        m_histList->Clear();
        SetTitle("Dose Counter - New Log");
    }
    dialog->Destroy();
}

void MainFrame::onSave(wxCommandEvent& evt) {
    wxCommandEvent emptyEvent;
    if (curDocPath == "")
        onSaveAs(emptyEvent);
    else
        saveDoses();
}

void MainFrame::onSaveAs(wxCommandEvent& evt) {
    wxFileDialog* fd = new wxFileDialog
    (this, "Choose File", "", "DosimeterLog.txt", "Text Files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	// Creates a "open file" dialog
	if (fd->ShowModal() == wxID_OK) { // if the user click "Open" instead of "Cancel"
        // Sets our current document to the file the user selected
		curDocPath = fd->GetPath();
        saveDoses();
        SetTitle(wxString("Dose Counter - ") << fd->GetFilename());
	}

	// Clean up after ourselves
	fd->Destroy();
}

void MainFrame::onUndo(wxCommandEvent& evt) {
    if (m_undoHist == 0)
        return;
    --m_undoHist;
    ++m_doses;
    updateCounter();
    m_histList->Delete(m_histList->GetCount() - 1);
}

void MainFrame::onDoseButtonClicked(wxCommandEvent &evt) {
    wxPuts(wxT("Button Clicked"));
    if (m_doses == 0)
        return;
    wxDateTime now = wxDateTime::Now();
    wxString doseDateTime = now.Format("%Y-%m-%d %H:%M");
    m_histList->AppendAndEnsureVisible(wxString::Format("%i: %s", m_doses, doseDateTime));
    --m_doses;
    ++m_undoHist;
    updateCounter();
    evt.Skip();
}

MainFrame::~MainFrame() {}
