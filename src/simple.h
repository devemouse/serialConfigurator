#include <wx/wx.h>
#include <wx/treebook.h>
#include "MainWindow.h"

class Simple : public MainFrame
{
   public:
      Simple(const wxString& title);

      virtual void MainWindowActivatedEvtHdl( wxActivateEvent& event );
		virtual void MainWindowCloseEvtHdl( wxCloseEvent& event );
      virtual void AddNoteEvtHdl( wxCommandEvent& event );
      virtual void FileSelectedEvtHdl( wxCommandEvent& event );
      virtual void ListFilesEvtHdl( wxFileDirPickerEvent& event );
		virtual void dbgButton01ClickEvtHdl( wxCommandEvent& event );
		virtual void dbgButton02ClickEvtHdl( wxCommandEvent& event );
		virtual void startDragHdl( wxCommandEvent& event );
		virtual void continueDragHdl( wxMouseEvent& event );
      void KeyEvtHdl( wxKeyEvent& event );
      

   protected:
      wxArrayString files;
      void ListFiles(void);
		wxTreebook* m_treeCtrl2;
};