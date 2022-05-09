#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include "mainFrame.h"

// The "Main" object of the app
class AsthmaApp : public wxApp {
private:
    // The primary frame; root window shown to the user.
    MainFrame* m_frame1;
public:
    virtual bool OnInit();
};

#endif
