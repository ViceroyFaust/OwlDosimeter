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

    wxButton *m_decButton;
    wxStaticText *m_counterLabel;

    void onQuit(wxCommandEvent& evt);
    void onButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif
