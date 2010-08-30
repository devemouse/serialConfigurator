#include "main.h"
#include "serialConfigurator.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
   SerialConfigurator *serialConfigurator = new SerialConfigurator(wxT("Serial Configurator"));

   this->Connect( wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler( SerialConfigurator::KeyEvtHdl ), NULL, serialConfigurator );

   serialConfigurator->Show(true);

   return true;
}
