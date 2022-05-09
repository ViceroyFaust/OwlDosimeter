#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

// The main window of the App
class MainFrame : public wxFrame {
public:
    MainFrame();
    ~MainFrame();

    int m_doses;

    wxMenuBar *m_menubar;
    wxMenu *m_file;

    wxStaticText *m_counterLabel;
    wxStaticText *m_histLabel;

    wxListBox *m_histList;

    wxButton *m_decButton;
    wxButton *m_undoButton;

    void onQuit(wxCommandEvent& evt);
    void onButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif
