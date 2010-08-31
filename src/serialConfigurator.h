#ifndef  serialconfigurator_INC
#define  serialconfigurator_INC

// #####   HEADER FILE INCLUDES   ###################################################
#include "MainWindow.h"


// #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ###################################
#define NUM_OF_BUTTONS 64

// #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ###############################
class wxButton;
class wxColour;
class wxTreebook;
class wxActivateEvent;
class wxCloseEvent;
class wxCommandEvent;
class wxFileDirPickerEvent;
class wxMouseEvent;
class wxScrollEvent;
class wxKeyEvent;


class SerialConfigurator : public MainFrame
{
   public:
      SerialConfigurator(const wxString& title);

      virtual void MainWindowActivatedEvtHdl( wxActivateEvent& event );
      virtual void MainWindowCloseEvtHdl( wxCloseEvent& event );
      virtual void AddNoteEvtHdl( wxCommandEvent& event );
      virtual void FileSelectedEvtHdl( wxCommandEvent& event );
      virtual void ListFilesEvtHdl( wxFileDirPickerEvent& event );
      virtual void dbgButton01ClickEvtHdl( wxCommandEvent& event );
      virtual void dbgButton02ClickEvtHdl( wxCommandEvent& event );
      virtual void startDragHdl( wxCommandEvent& event );
      virtual void continueDragHdl( wxMouseEvent& event );
      virtual void BSS_OnScrollHdl( wxScrollEvent& event );
      virtual void BPS_OnScrollHdl( wxScrollEvent& event );
      void KeyEvtHdl( wxKeyEvent& event );

   private:
      void clearButtons(void);
      void drawSignal(int pos, int size);

   protected:
      wxArrayString files;
      void ListFiles(void);
      wxTreebook* m_treeCtrl2;
      wxButton * buttons[64];
      wxColour * defaultButtonColour;
};
#endif   /* ----- #ifndef serialconfigurator_INC  ----- */
