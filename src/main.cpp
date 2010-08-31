// =====================================================================================
// 
//       Filename:  main.cpp
// 
//    Description:  Main application. Creates main window.
// 
//        Version:  1.0
//        Created:  2010-08-31 08:08:47
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Dariusz Synowiec (darek129), darek129@gmail.com
// 
// =====================================================================================

// #####   HEADER FILE INCLUDES   ###################################################

#include "main.h"
#include "serialConfigurator.h"

// #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
   SerialConfigurator *serialConfigurator = new SerialConfigurator(wxT("Serial Configurator"));

   this->Connect( wxID_ANY, wxEVT_KEY_DOWN, wxKeyEventHandler( SerialConfigurator::KeyEvtHdl ), NULL, serialConfigurator );

   serialConfigurator->Show(true);

   return true;
}
