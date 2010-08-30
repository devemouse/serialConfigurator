#ifndef  serialconfigurator_INC
#define  serialconfigurator_INC
#include <wx/wx.h>
#include <wx/treebook.h>
#include "MainWindow.h"

#define NUM_OF_BUTTONS 64

class wxButton;
class wxColour;

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


   protected:
      wxArrayString files;
      void ListFiles(void);
      wxTreebook* m_treeCtrl2;
      wxButton * buttons[64];
      wxColour * defaultButtonColour;
};
#endif   /* ----- #ifndef serialconfigurator_INC  ----- */
