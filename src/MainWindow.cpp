///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainWindow.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_filesList = new wxListBox( this, ID_FILES_LIST, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	bSizer1->Add( m_filesList, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_workingDirPicker = new wxDirPickerCtrl( this, ID_DIR_PICKER, wxT("../tmpcfg/"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizer3->Add( m_workingDirPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_Text = new wxRichTextCtrl( this, ID_TEXT_BOX, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0|wxHSCROLL|wxSIMPLE_BORDER|wxVSCROLL|wxWANTS_CHARS );
	bSizer3->Add( m_Text, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textLine = new wxTextCtrl( this, ID_TEXT_LINE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxSIMPLE_BORDER );
	bSizer2->Add( m_textLine, 1, wxALL|wxEXPAND, 5 );
	
	m_addButton = new wxButton( this, ID_ADD_BUTTON, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addButton->SetDefault(); 
	bSizer2->Add( m_addButton, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer3->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_dbgButton01 = new wxButton( this, ID_DBG_BUTTON_01, wxT("m_dbgButton01"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_dbgButton01, 0, wxALL|wxEXPAND, 1 );
	
	m_dbgButton02 = new wxButton( this, ID_DBG_BUTTON_01, wxT("m_dbgButton02"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_dbgButton02, 0, wxALL|wxEXPAND, 1 );
	
	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );
	
	m_mainTree = new wxTreeCtrl( this, wxID_TREE, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_HAS_BUTTONS );
	bSizer1->Add( m_mainTree, 2, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->SetSashGravity( 0 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter1OnIdle ), NULL, this );
	m_panel2 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_Properties = new wxTreeCtrl( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT );
	bSizer8->Add( m_Properties, 2, wxALL|wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer8 );
	m_panel2->Layout();
	bSizer8->Fit( m_panel2 );
	m_panel4 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl2 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrl2, 0, wxALL|wxEXPAND, 5 );
	
	m_textCtrl3 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrl3, 0, wxALL|wxEXPAND, 5 );
	
	m_textCtrl4 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrl4, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bit_size_slider = new wxSlider( m_panel4, wxID_BS_SLIDER, 5, 1, 64, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer6->Add( m_bit_size_slider, 1, wxALL|wxEXPAND, 5 );
	
	m_bit_size_label = new wxStaticText( m_panel4, wxID_ANY, wxT("BS: 00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bit_size_label->Wrap( -1 );
	bSizer6->Add( m_bit_size_label, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bit_pos_slider = new wxSlider( m_panel4, wxID_BP_SLIDER, 5, 0, 63, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer61->Add( m_bit_pos_slider, 1, wxALL|wxEXPAND, 5 );
	
	m_bit_pos_label = new wxStaticText( m_panel4, wxID_ANY, wxT("BP: 00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bit_pos_label->Wrap( -1 );
	bSizer61->Add( m_bit_pos_label, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer61, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, wxT("Description") ), wxVERTICAL );
	
	m_optionDescription = new wxStaticText( m_panel4, wxID_ANY, wxT("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam condimentum leo non libero volutpat molestie. Nullam vitae ante ullamcorper velit tempor volutpat eget eu sem. Nulla id velit nulla, id molestie velit. Aliquam erat volutpat. Nulla consectetur nibh quis dolor tincidunt at lobortis sem pretium. Integer ligula neque, semper vel pellentesque sit amet, gravida accumsan diam. Integer enim nisi, volutpat a consequat quis, luctus nec tortor. Nam a mollis nisl. Duis massa tortor, tempus accumsan porta vitae, sodales ac odio. Proin eget mauris purus, sed facilisis nibh. Suspendisse rhoncus leo ac massa consectetur eu rhoncus odio tempor. Nulla ullamcorper fringilla enim. Nam eleifend tempor dolor, nec sagittis lorem lobortis ut. Morbi est eros, feugiat ac placerat ac, lacinia vel tortor. Vivamus commodo, mauris lobortis imperdiet fringilla, nulla metus pretium velit, a mollis urna ipsum quis augue.\n"), wxDefaultPosition, wxDefaultSize, 0 );
	m_optionDescription->Wrap( -1 );
	sbSizer2->Add( m_optionDescription, 1, wxALL|wxEXPAND, 5 );
	
	bSizer10->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	m_genericSlider = new wxSlider( m_panel4, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer10->Add( m_genericSlider, 0, wxALL|wxEXPAND, 5 );
	
	m_panel4->SetSizer( bSizer10 );
	m_panel4->Layout();
	bSizer10->Fit( m_panel4 );
	m_splitter1->SplitVertically( m_panel2, m_panel4, 150 );
	bSizer5->Add( m_splitter1, 4, wxEXPAND, 5 );
	
	buttonsSizer = new wxGridSizer( 8, 8, 0, 0 );
	
	buttonsSizer->SetMinSize( wxSize( 600,600 ) ); 
	bSizer5->Add( buttonsSizer, 3, wxALIGN_CENTER|wxEXPAND|wxFIXED_MINSIZE|wxSHAPED, 1 );
	
	bSizer1->Add( bSizer5, 5, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( MainFrame::MainWindowActivatedEvtHdl ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::MainWindowCloseEvtHdl ) );
	m_filesList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrame::FileSelectedEvtHdl ), NULL, this );
	m_workingDirPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( MainFrame::ListFilesEvtHdl ), NULL, this );
	m_addButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::AddNoteEvtHdl ), NULL, this );
	m_dbgButton01->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::dbgButton01ClickEvtHdl ), NULL, this );
	m_dbgButton02->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::dbgButton02ClickEvtHdl ), NULL, this );
	m_mainTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MainFrame::TreeSelChangedHdl ), NULL, this );
	m_Properties->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MainFrame::PropTreeSelChangedHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( MainFrame::MainWindowActivatedEvtHdl ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::MainWindowCloseEvtHdl ) );
	m_filesList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrame::FileSelectedEvtHdl ), NULL, this );
	m_workingDirPicker->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( MainFrame::ListFilesEvtHdl ), NULL, this );
	m_addButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::AddNoteEvtHdl ), NULL, this );
	m_dbgButton01->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::dbgButton01ClickEvtHdl ), NULL, this );
	m_dbgButton02->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::dbgButton02ClickEvtHdl ), NULL, this );
	m_mainTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MainFrame::TreeSelChangedHdl ), NULL, this );
	m_Properties->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MainFrame::PropTreeSelChangedHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_size_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrame::BSS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
	m_bit_pos_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrame::BPS_OnScrollHdl ), NULL, this );
}
