#ifndef CMAIN_H
#define CMAIN_H

#include <wx/wx.h>

class cMain : public wxFrame {
public:
    cMain();
    ~cMain();

    wxButton *m_btn1 = nullptr;
    wxTextCtrl *m_txt1 = nullptr;
    wxListBox *m_list1 = nullptr;
};

#endif // CMAIN_H
