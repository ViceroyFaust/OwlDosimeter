#ifndef CMAIN_H
#define CMAIN_H

#include <wx/wx.h>

// The main window of the App
class cMain : public wxFrame {
public:
    cMain();
    ~cMain();

    int m_doses;

    wxMenuBar *m_menubar;
    wxMenu *m_file;

    wxButton *m_btn1;
    wxStaticText *m_text;

    void onQuit(wxCommandEvent& evt);
    void onButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif // CMAIN_H
