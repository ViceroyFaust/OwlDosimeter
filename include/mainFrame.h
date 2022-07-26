#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

enum ButtonId {
    doseButtonId = wxID_LAST + 1,
    undoButtonId
};

// The main window of the App
class MainFrame : public wxFrame {
private:
    void saveDoses();
public:
    MainFrame();
    ~MainFrame();

    int m_doses;

    wxString curDocPath;

    wxMenuBar *m_menubar;
    wxMenu *m_file;

    wxStaticText *m_counterLabel;
    wxStaticText *m_histLabel;

    wxListBox *m_histList;

    wxButton *m_doseButton;
    wxButton *m_undoButton;

    void onQuit(wxCommandEvent& evt);
    void onNew(wxCommandEvent& evt);
    void onSave(wxCommandEvent& evt);
    void onSaveAs(wxCommandEvent& evt);
    void onDoseButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif
