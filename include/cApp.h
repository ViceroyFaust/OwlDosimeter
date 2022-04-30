#ifndef CAPP_H
#define CAPP_H

#include <wx/wx.h>
#include "cMain.h"

class cApp : public wxApp {
private:
    cMain* m_frame1;
public:
    virtual bool OnInit();
};

#endif // CAPP_H
