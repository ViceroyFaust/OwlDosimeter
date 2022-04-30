#ifndef CMAIN_H
#define CMAIN_H

#include <wx/wx.h>

class cMain : public wxFrame {
public:
    cMain();
    ~cMain();

    wxButton *m_btn1;
    wxTextCtrl *m_txt1;
    wxListBox *m_list1;

    void onButtonClicked(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

#endif // CMAIN_H
