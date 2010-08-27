#include "main.h"
#include "simple.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
   Simple *simple = new Simple(wxT("Simple"));

   this->Connect( wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler( Simple::KeyEvtHdl ), NULL, simple );

   simple->Show(true);

   return true;
}
