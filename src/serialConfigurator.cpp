#include "serialConfigurator.h"
#include "wx/panel.h"
#include "wx/menu.h"
#include "wx/dir.h"
#include "wx/filename.h"
#include "wx/textfile.h"
#include "wx/msgdlg.h"
#include "wx/dnd.h"
#include "wx/colour.h"
#include "home.xpm"


/*-----------------------------------------------------------------------------
 *  Constructor
 *-----------------------------------------------------------------------------*/
   SerialConfigurator::SerialConfigurator(const wxString& title)
: MainFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 550))
{
   SetIcon(wxIcon(wxICON(home)));

   //wxButton * buttons[64];

   for (int i=0; i<NUM_OF_BUTTONS; i++)
   {
      buttons[i] = new wxButton(this, i, wxString::Format(wxT("%d"), i), wxDefaultPosition, wxSize(-1,-1));
      buttonsSizer->Add(buttons[i], 0, wxALL|wxEXPAND, 0);
      buttons[i]->Connect( wxEVT_LEFT_DOWN, wxCommandEventHandler( SerialConfigurator::startDragHdl ), NULL, this );
      buttons[i]->Connect( wxEVT_MOTION, wxMouseEventHandler( SerialConfigurator::continueDragHdl ), NULL, this );
   }
	this->Layout();
   defaultButtonColour = new wxColour(buttons[0]->GetBackgroundColour());

   m_bit_pos_label->SetLabel(wxString::Format(wxT("BP: %d "), 5));
   m_bit_size_label->SetLabel(wxString::Format(wxT("BS: %d "), 5));
   clearButtons();
   drawSignal(5,5);

   // Centre();
   //wxPanel *panel = new wxPanel(this, wxID_ANY);
   //wxMenuBar *mbar = new wxMenuBar;
   //wxMenu *menuWidget = new wxMenu;
   //menuWidget->Append(4, _T("&Otwórz\tCtrl-O"));
   //mbar->Append(menuWidget, _T("&Plik"));

   //SetMenuBar(mbar);

   //RegisterHotKey(0x5555, wxMOD_WIN, 'I');

//RegisterHotKey( NULL, 1, wxMOD_NOREPEAT, 0x49);  //0x49 is 'I'
   
   //const wxTreeItemId RootNode = m_treeCtrl1->AddRoot("root");
   //m_treeCtrl1->AppendItem(RootNode, "sub1");
   //m_treeCtrl1->AppendItem(RootNode, "sub2");
   //m_treeCtrl1->AppendItem(RootNode, "sub3");
   
	//m_treeCtrl2 = new wxTreebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );

	//this->GetSizer()->Add( m_treeCtrl2, 1, wxALL|wxEXPAND, 5 );

   //wxWindow *page_p = NULL;
   //m_treeCtrl2->AddPage(page_p, "Page 1");
   //m_treeCtrl2->AddSubPage(page_p, "Page 1.1");
   //m_treeCtrl2->AddPage(NULL, "Page 2");
   //m_treeCtrl2->AddPage(NULL, "Page 3");

   //ListFiles();
   //m_Text->LoadFile(files[m_filesList->GetSelection()]);
}
   //m_textLine->SetFocus();

/*-----------------------------------------------------------------------------
 *  Event Handlers
 *-----------------------------------------------------------------------------*/
void SerialConfigurator::KeyEvtHdl( wxKeyEvent& event )
{
   if (event.GetModifiers() == wxMOD_CONTROL )
   {
      switch (event.GetKeyCode())
      {
         case '/':
            {
               wxString temp;
               //temp.Printf(wxT("%d"), event.GetKeyCode());
               temp.Printf(wxT("Selection: %d\nCount: %d"), m_filesList->GetSelection(), m_filesList->GetCount());
               wxMessageBox( temp, _T("DEBUG"), wxOK);
            }
            break;

         case 'J':
            {
               int selection = m_filesList->GetSelection();
               if (wxNOT_FOUND == selection) selection = -1;

               if (selection < (int) m_filesList->GetCount())
               {
                  selection++;
                  m_filesList->SetSelection(selection);
                  m_Text->SaveFile();
                  m_Text->LoadFile(files[selection]);
               }
            }
            break;

         case 'K':
            {
               int selection = m_filesList->GetSelection();
               if (wxNOT_FOUND == selection) selection = m_filesList->GetCount();

               if (selection > 0)
               {
                  selection--;
                  m_filesList->SetSelection(selection);
                  m_Text->SaveFile();
                  m_Text->LoadFile(files[selection]);
               }
            }
            break;

         case 'O':
            {
               wxDirDialog tmpDialog(this, wxT("Select a folder"), wxFileName::FileName(files[0]).GetPath());

               if ( wxID_OK == tmpDialog.ShowModal())
               {
                  m_workingDirPicker->SetPath(tmpDialog.GetPath());
                  ListFiles();
               }
            }
            break;

         case 'I':
            m_Text->SetFocus();
            break;

         default:
            event.Skip();
            break;
      }
   }
   else
   {
      switch (event.GetKeyCode())
      {
         case WXK_ESCAPE:
            this->Close(false);
            break;
         default:
            event.Skip();
            break;
      }
   }
}

void SerialConfigurator::MainWindowActivatedEvtHdl( wxActivateEvent& event )
{
}

void SerialConfigurator::MainWindowCloseEvtHdl( wxCloseEvent& event )
{ 
   m_Text->SaveFile();
   event.Skip();
}



void SerialConfigurator::startDragHdl( wxCommandEvent& event )
{
   m_Text->AppendText(wxString::Format(wxT("\n%d "), event.GetId()));

   //wxTextDataObject textData("This text will be dragged.");
   //wxDropSource source(textData, this);

   //wxDragResult result = source.DoDragDrop(TRUE);

      //event.Skip();
}

void SerialConfigurator::continueDragHdl( wxMouseEvent& event )
{
   //if (event.Dragging()){
      m_Text->AppendText(wxString::Format(wxT("%d "), event.GetId()));
   //}

   event.Skip();
}


void SerialConfigurator::BSS_OnScrollHdl( wxScrollEvent& event )
{
   int size = m_bit_size_slider->GetValue();
   int pos = m_bit_pos_slider->GetValue();

   m_bit_size_label->SetLabel(wxString::Format(wxT("BS: %d "), size));

   drawSignal(pos,size);

   event.Skip();
}


void SerialConfigurator::clearButtons(void)
{
   for (int i=0; i<NUM_OF_BUTTONS; i++)
   {
      buttons[i]->SetBackgroundColour(*defaultButtonColour);
   }
}

void SerialConfigurator::drawSignal(int pos, int size)
{
   clearButtons();

   if (size + pos <= NUM_OF_BUTTONS)
   {
      for (int i = pos; i<(pos + size); i++)
      {
         buttons[i]->SetBackgroundColour(wxColour(0xFF,0xFF,0xFF));
      }
   }
   else
   {
      //m_bit_size_slider->SetValue(NUM_OF_BUTTONS);
   }

}

void SerialConfigurator::BPS_OnScrollHdl( wxScrollEvent& event )
{
   int size = m_bit_size_slider->GetValue();
   int pos = m_bit_pos_slider->GetValue();

   m_bit_pos_label->SetLabel(wxString::Format(wxT("BP: %d "), pos));

   clearButtons();

   drawSignal(pos,size);

   event.Skip();
}

void SerialConfigurator::FileSelectedEvtHdl( wxCommandEvent& event )
{
   m_Text->SaveFile();
   m_Text->LoadFile(files[m_filesList->GetSelection()]);
   event.Skip(); 
}

void SerialConfigurator::ListFilesEvtHdl( wxFileDirPickerEvent& event )
{
   ListFiles();
   event.Skip(); 
}

void SerialConfigurator::AddNoteEvtHdl( wxCommandEvent& event )
{ 
   m_Text->AppendText(m_textLine->GetValue() + wxT("\n"));
   m_textLine->Clear();
   event.Skip(); 
}

void SerialConfigurator::dbgButton01ClickEvtHdl( wxCommandEvent& event )
{
   m_filesList->Clear();
   event.Skip();
}

void SerialConfigurator::dbgButton02ClickEvtHdl( wxCommandEvent& event )
{
   ///wxMessageBox( _T("DebugButton 02"), _T("DEBUG"), wxOK);
   m_Text->SaveFile();
   event.Skip();
}

/*-----------------------------------------------------------------------------
 *  Helper functinos
 *-----------------------------------------------------------------------------*/
void SerialConfigurator::ListFiles(void)
{
   //wxMessageBox( _T("ListFiles called"), _T("info"), wxOK);

   m_filesList->Clear();
   files.Clear();

   //get files list
   wxDir(m_workingDirPicker->GetPath()).GetAllFiles(m_workingDirPicker->GetPath(), &files, wxT("*.txt"));

   //convert full paths to file names without extension.
   wxArrayString fileNames;
   wxString temp;
   for (int i =0; i< files.GetCount(); i++)
   {
      wxFileName::SplitPath(files[i], NULL, NULL, &temp, NULL);
      fileNames.Add(temp);
   }

   //add file names to list control
   m_filesList->InsertItems(fileNames,0);
   m_filesList->SetSelection(0);
}


