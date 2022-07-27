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
    int m_doses;
    int m_undoHist;
    wxString curDocPath;

    void saveDoses();
    void updateCounter();
public:
    MainFrame();
    ~MainFrame();

    wxMenuBar *m_menubar;
    wxMenu *m_file;
    wxMenu *m_edit;

    wxStaticText *m_counterLabel;
    wxStaticText *m_histLabel;

    wxListBox *m_histList;

    wxButton *m_doseButton;
    wxButton *m_undoButton;

    void onQuit(wxCommandEvent& evt);
    void onOpen(wxCommandEvent& evt);
    void onNew(wxCommandEvent& evt);
    void onSave(wxCommandEvent& evt);
    void onSaveAs(wxCommandEvent& evt);
    void onUndo(wxCommandEvent& evt);
    void onDoseButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif
