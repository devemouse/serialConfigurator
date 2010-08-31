#ifndef _MESSAGEGUI_H_
#define _MESSAGEGUI_H_
// =====================================================================================
// 
//       Filename:  MessageGUI.h
// 
//    Description:  Header for MessageGUI.cpp
// 
//        Version:  1.0
//        Created:  2010-08-31 08:06:15
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Dariusz Synowiec (darek129), darek129@gmail.com
// 
// =====================================================================================



// #####   HEADER FILE INCLUDES   ###################################################

#include <wx/control.h>

// #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ###################################

#define NUM_OF_BUTTONS 64

// #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   #########################

class wxGridSizer;
class wxButton;
class wxColour;


// #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ###############################

// #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################

// #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ###############################

// #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################

// #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   #####################

class MessageGUI : public wxWindow
{
   public:
      MessageGUI();
      MessageGUI(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxT("MainFrame"));

      //virtual void MainWindowActivatedEvtHdl( wxActivateEvent& event );
      //virtual void MainWindowCloseEvtHdl( wxCloseEvent& event );
      //virtual void AddNoteEvtHdl( wxCommandEvent& event );
      //virtual void FileSelectedEvtHdl( wxCommandEvent& event );
      //virtual void ListFilesEvtHdl( wxFileDirPickerEvent& event );
      //virtual void dbgButton01ClickEvtHdl( wxCommandEvent& event );
      //virtual void dbgButton02ClickEvtHdl( wxCommandEvent& event );
      //virtual void startDragHdl( wxCommandEvent& event );
      //virtual void continueDragHdl( wxMouseEvent& event );
      //virtual void BSS_OnScrollHdl( wxScrollEvent& event );
      //virtual void BPS_OnScrollHdl( wxScrollEvent& event );
      //void KeyEvtHdl( wxKeyEvent& event );

   //private:
      //void clearButtons(void);
      //void drawSignal(int pos, int size);

   protected:
		wxGridSizer* buttonsSizer;
      wxButton * buttons[NUM_OF_BUTTONS];
      wxColour * defaultButtonColour;
      //wxArrayString files;
      //void ListFiles(void);
      //wxTreebook* m_treeCtrl2;
      //wxButton * buttons[64];
      //wxColour * defaultButtonColour;
};

#endif

