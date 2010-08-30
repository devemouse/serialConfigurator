#include "serialConfigurator.h"
#include "wx/panel.h"
#include "wx/menu.h"
#include "wx/dir.h"
#include "wx/filename.h"
#include "wx/textfile.h"
#include "wx/msgdlg.h"
#include "wx/dnd.h"
#include "home.xpm"



/*-----------------------------------------------------------------------------
 *  Constructor
 *-----------------------------------------------------------------------------*/
   SerialConfigurator::SerialConfigurator(const wxString& title)
: MainFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 550))
{
   SetIcon(wxIcon(wxICON(home)));

   wxButton * buttons[64];

   char buf[5];

   for (int i=0; i<64; i++)
   {
      sprintf(buf,"%d", i);
      buttons[i] = new wxButton(this, i, buf, wxDefaultPosition, wxSize(-1,-1), wxNO_BORDER);
      buttonsSizer->Add(buttons[i], 0, wxALL|wxEXPAND, 0);
      buttons[i]->Connect( wxEVT_LEFT_DOWN, wxCommandEventHandler( SerialConfigurator::startDragHdl ), NULL, this );
      buttons[i]->Connect( wxEVT_MOTION, wxMouseEventHandler( SerialConfigurator::continueDragHdl ), NULL, this );
   }
	this->Layout();

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
   char buf[5];
   sprintf(buf,"\n%d ", event.GetId());

   m_Text->AppendText(buf);

   //wxTextDataObject textData("This text will be dragged.");
   //wxDropSource source(textData, this);

   //wxDragResult result = source.DoDragDrop(TRUE);

      //event.Skip();
}

void SerialConfigurator::continueDragHdl( wxMouseEvent& event )
{
   if (event.Dragging()){

      char buf[5];
      sprintf(buf,"%d ", event.GetId());

      m_Text->AppendText(buf);
   }

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


