#ifndef CMAIN_H
#define CMAIN_H

#include <wx/wx.h>

// The main window of the App
class cMain : public wxFrame {
public:
    cMain();
    ~cMain();

    wxMenuBar *m_menubar;
    wxMenu *m_file;

    wxButton *m_btn1;
    wxTextCtrl *m_txt1;
    wxListBox *m_list1;

    void onQuit(wxCommandEvent& evt);
    void onButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif // CMAIN_H
