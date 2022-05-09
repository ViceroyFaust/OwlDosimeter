#include "main.h"

wxIMPLEMENT_APP(AsthmaApp);

bool AsthmaApp::OnInit() {
    m_frame1 = new MainFrame();
    m_frame1->Show();
    wxPuts(wxT("App Initialized"));
    return true;
}
