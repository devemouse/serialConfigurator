#ifndef  _IPDU_H_
#define  _IPDU_H_

#include <wx/treectrl.h>
#include <wx/string.h>
#include "signal.h"

WX_DECLARE_STRING_HASH_MAP( int, ArrayOfProperties );
WX_DECLARE_OBJARRAY(Signal*, ArrayOfSignals);

class Ipdu : public wxTreeItemData
{
   public:
      Ipdu()
      {
         signals = new ArrayOfSignals();
      }

      Ipdu(int _bit_size = 1, int _bit_position = 0)
      {
         signals = new ArrayOfSignals();
      }

      //Ipdu(int ID, int _bit_size = 1, int _bit_position = 0) 
      //{
         //Properties[wxT("HandleId")] = ID;
         //Properties[wxT("BitSize")] = _bit_size;
         //Properties[wxT("BitPosition")] = _bit_position;
      //}

      ~Ipdu(){};

      int GetPropertyValue(const wxString& _property_name = wxT("nil")) { return Properties[_property_name]; }
      void SetPropertyValue(const wxString& _property_name = wxT("nil"), int _value = 0){ Properties[_property_name] = _value; } 

      int GetBitSize() { 
         return Properties[wxT("BitSize")]; 
      }
      void SetBitSize(int _bs) {
         Properties[wxT("BitSize")] = _bs; 
      }

      int GetBitPosition() {
         return Properties[wxT("BitPosition")]; 
      }
      void SetBitPosition(int _bp) {
         Properties[wxT("BitPosition")] = _bp; 
      }


      void Add(Signal* _signal) {signals->Add(_signal); }

      ArrayOfSignals* GetSignals(void) {return signals;}


   protected:
      ArrayOfProperties Properties;
      ArrayOfSignals * signals;
      //int BitPosition;                            /**< starting bit position in IPDU */
      //int BitSize;                                /**< how many bits does the signal take in IPdu */

};

#endif   // ----- #ifndef _IPDU_H_  -----
