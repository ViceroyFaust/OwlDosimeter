#ifndef CAPP_H
#define CAPP_H

#include <wx/wx.h>
#include "cMain.h"

// The "Main" object of the app
class cApp : public wxApp {
private:
    // The primary frame; root window shown to the user.
    cMain* m_frame1;
public:
    virtual bool OnInit();
};

#endif // CAPP_H
