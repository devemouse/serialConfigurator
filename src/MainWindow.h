///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MainWindow__
#define __MainWindow__

#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/treectrl.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/slider.h>
#include <wx/splitter.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			ID_FILES_LIST = 1000,
			ID_DIR_PICKER,
			ID_TEXT_BOX,
			ID_TEXT_LINE,
			ID_ADD_BUTTON,
			ID_DBG_BUTTON_01,
			wxID_TREE,
			wxID_BP_SLIDER,
			wxID_BS_SLIDER,
		};
		
		wxListBox* m_filesList;
		wxDirPickerCtrl* m_workingDirPicker;
		wxRichTextCtrl* m_Text;
		wxTextCtrl* m_textLine;
		wxButton* m_addButton;
		wxButton* m_dbgButton01;
		wxButton* m_dbgButton02;
		wxTreeCtrl* m_mainTree;
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel2;
		wxTreeCtrl* m_Properties;
		wxPanel* m_panel4;
		wxTextCtrl* m_textCtrl2;
		wxTextCtrl* m_textCtrl3;
		wxTextCtrl* m_textCtrl4;
		wxStaticText* m_optionDescription;
		wxSlider* m_genericSlider;
		wxSlider* m_bit_pos_slider;
		wxStaticText* m_bit_pos_label;
		wxSlider* m_bit_size_slider;
		wxStaticText* m_bit_size_label;
		wxGridSizer* buttonsSizer;
		
		// Virtual event handlers, overide them in your derived class
		virtual void MainWindowActivatedEvtHdl( wxActivateEvent& event ){ event.Skip(); }
		virtual void MainWindowCloseEvtHdl( wxCloseEvent& event ){ event.Skip(); }
		virtual void FileSelectedEvtHdl( wxCommandEvent& event ){ event.Skip(); }
		virtual void ListFilesEvtHdl( wxFileDirPickerEvent& event ){ event.Skip(); }
		virtual void AddNoteEvtHdl( wxCommandEvent& event ){ event.Skip(); }
		virtual void dbgButton01ClickEvtHdl( wxCommandEvent& event ){ event.Skip(); }
		virtual void dbgButton02ClickEvtHdl( wxCommandEvent& event ){ event.Skip(); }
		virtual void TreeSelChangedHdl( wxTreeEvent& event ){ event.Skip(); }
		virtual void PropTreeSelChangedHdl( wxTreeEvent& event ){ event.Skip(); }
		virtual void BPS_OnScrollHdl( wxScrollEvent& event ){ event.Skip(); }
		virtual void BSS_OnScrollHdl( wxScrollEvent& event ){ event.Skip(); }
		
	
	public:
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MainFrame"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 857,828 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();
		void m_splitter1OnIdle( wxIdleEvent& )
		{
		m_splitter1->SetSashPosition( 150 );
		m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter1OnIdle ), NULL, this );
		}
		
	
};

#endif //__MainWindow__
