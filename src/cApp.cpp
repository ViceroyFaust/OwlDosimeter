#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit() {
    m_frame1 = new cMain();
    m_frame1->Show();
    wxPuts(wxT("App Initialized"));
    return true;
}
