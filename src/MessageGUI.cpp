// =====================================================================================
// 
//       Filename:  MessageGUI.cpp
// 
//    Description:  Set of buttons representing a message.
// 
//        Version:  1.0
//        Created:  2010-08-31 08:02:23
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Dariusz Synowiec (darek129), darek129@gmail.com
// 
// =====================================================================================


#include "MessageGUI.h"
#include "wx/sizer.h"
#include "wx/button.h"
#include "wx/colour.h"

// #####   HEADER FILE INCLUDES   ###################################################

// #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ###################################


// #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   #########################

// #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ###############################

// #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################

// #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ###############################

// #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################

// #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   #####################

MessageGUI::MessageGUI()
{

}

MessageGUI::MessageGUI(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
: wxWindow(parent, id, pos, size, style, name)
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	buttonsSizer = new wxGridSizer( 8, 8, 0, 0 );
	buttonsSizer->SetMinSize( wxSize( 80,80 ) ); 

   for (int i=0; i<NUM_OF_BUTTONS; i++)
   {
      buttons[i] = new wxButton(this, i, wxString::Format(wxT("%d"), i), wxDefaultPosition, wxDefaultSize);
      buttonsSizer->Add(buttons[i], 0, wxALL|wxEXPAND, 0);
      //buttons[i]->Connect( wxEVT_LEFT_DOWN, wxCommandEventHandler( SerialConfigurator::startDragHdl ), NULL, this );
      //buttons[i]->Connect( wxEVT_MOTION, wxMouseEventHandler( SerialConfigurator::continueDragHdl ), NULL, this );
   }

	
	//m_button7 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	//buttonsSizer->Add( m_button7, 0, wxALL, 5 );
	
	//m_button8 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	//buttonsSizer->Add( m_button8, 0, wxALL, 5 );

	//bSizer5->Add( buttonsSizer, 0, wxEXPAND, 5 );

	this->SetSizerAndFit( buttonsSizer, true);
   buttonsSizer->FitInside(this);
	this->Layout();
}


