#ifndef  _SIGNAL_H_
#define  _SIGNAL_H_

#include <wx/treectrl.h>

//typedef signed char sint8;
//typedef unsigned char uint8;
//typedef signed short sint16;
//typedef unsigned short uint16;
//typedef signed long sint32;
//typedef unsigned long uint32;
//typedef unsigned long uint8_least;
//typedef unsigned long uint16_least;
//typedef unsigned long uint32_least;
//typedef signed long sint8_least;
//typedef signed long sint16_least;
//typedef signed long sint32_least;

typedef int IPduType;
typedef int FilterType;
typedef int _SignalIdType;

typedef void (*FunctionNameDef) (void);

WX_DECLARE_STRING_HASH_MAP( int, MyHash );

/** 
 * The AUTOSAR type of the signal. 
 * Whether or not the signal is signed or unsigned can be found by examining the value of this attribute. 
 */
typedef enum {
   COM_BOOLEAN_COM_SIGNAL_TYPE,
   COM_UINT8_COM_SIGNAL_TYPE,
   COM_SINT8_COM_SIGNAL_TYPE,
   COM_UINT16_COM_SIGNAL_TYPE,
   COM_SINT16_COM_SIGNAL_TYPE,
   COM_UINT32_COM_SIGNAL_TYPE,
   COM_SINT32_COM_SIGNAL_TYPE,
   COM_UINT8_N_COM_SIGNAL_TYPE,
   COM_NUM_OF_SIGNAL_TYPES
} SignalTypeType;

/** 
 * Defines the endianness of the signal's network representation. 
 */
typedef enum {
   COM_BIG_ENDIAN,
   COM_LITTLE_ENDIAN,
   COM_OPAQUE
} SignalEndianessType;

/** 
 * This parameter defines the action performed upon reception of an invalid signal. 
 * Relating to signal groups the action in case if one of the included signals 
 * is an invalid signal. If Replace is used the ComSignalInitValue will be 
 * used for the replacement. 
 */
typedef enum {
   COM_NOTIFY_WHEN_INVALID_DATA,
   COM_REPLACE_WHEN_INVALID_DATA
} DataInvalidActionType;


/** Defines whether signals will participate in Transmission Condition Evaluation */
typedef enum {
   COM_PENDING_SIGNAL_TRANSFER,  /**< Signal won't participate in Transmission Condition Evaluation */
   COM_TRIGGERED_SIGNAL_TRANSFER /**< Signal will participate in Transmission Condition Evaluation */
} TransferPropertyType;

/** 
 * COM412: This parameter defines the action performed upon a reception timeout violation. 
 * COM500: If this parameter is omitted or configured to None no replacement shall take place. 
 * COM470: Relating to signals: 
 *         When this parameter is set to Replace, the replacement value used shall be the ComInitValue. 
 * COM513: Relating to signal groups: 
 *         When this parameter is set to Replace, all included signals shall be set to their ComInitValue. 
 */
typedef enum {
   COM_NONE_RX_TIMEOUT_ACTION,
   COM_REPLACE_RX_TIMEOUT_ACTION
} RxDataTimeoutActionType;





class Signal : public wxTreeItemData
{
   public:
      Signal();

      Signal(int _bit_size = 1, int _bit_position = 0);
      Signal(int ID, int _bit_size = 1, int _bit_position = 0) : HandleId(ID), BitSize(_bit_size), BitPosition(_bit_position){}
      ~Signal();

      int GetBitSize() { return Options["BitSize"]; }
      void SetBitSize(int _bs) { Options["BitSize"] = _bs; }

      int GetBitPosition() { return Options["BitPosition"]; }
      void SetBitPosition(int _bp) { Options["BitPosition"] = _bp; }



      MyHash Options;



      FunctionNameDef Notification;                   /**< txAck/rxAck notification */
      FunctionNameDef ErrorNotification;              /**< notification function on error */
      FunctionNameDef InvalidNotification;            /**< reference to notification function that is called when signal is invalid */
      FunctionNameDef TimeoutNotification;            /**< for deadline monitoring */

      IPduType* IPdulRef;                          /**< reference to IPdu the signal belongs to */
      FilterType* Filter;                          /**< filter used in TMS and callback notifications */

      int SignalInitValue;                       /**< signal will be initialized with this value upon execution of Com_Init */
      int SignalDataInvalidValue;                /**< signal specific invalid value */

      SignalTypeType SignalType;                   /**< type of the signal (Uint8, bool, etc.) */
      SignalEndianessType SignalEndianess;         /**< defines endianess of the signal */

      /**
       * COM393:  In  case  of  an  Rx-timeout  it  shall  be  configurable  whether  COM  replaces 
       * the signal/ signal group value with the initial value or keeps it as it is. In case of re-
       * placement the old_value of the corresponding filter-object (if configured) shall not be 
       * replaced. 
       */
      DataInvalidActionType DataInvalidAction;     /**< what to do on bad reception */
      TransferPropertyType TransferProperty;       /**< if signal contributes to the selection of IPDU tx, set this to TRIGGERED */
      _SignalIdType HandleId;                      /**< ID */

      RxDataTimeoutActionType RxDataTimeoutAction; /**< what to do on timeout */

#if (STD_OFF == COM_TIMEOUTS_IPDU_BASE_ONLY)
      /**
       * COM292:  In  the  case  where  reception  deadline  monitoring  is  used  on  signals  with 
       * update-bits, there shall be a separate reception deadline monitoring for each signal/ 
       * signal group with an update-bit
       */
      int TimeoutFactor;                         /**< for deadline monitoring */
      int FirstTimeoutFactor;                    /**< for deadline monitoring */
#endif

      int SignalLength;                           /**< in bytes for uint8 arrays */

#if COM_UPDATE_BITS_SUPPORT == STD_ON
      int UpdateBitPosition;                      /**< update bit position within IPDU. */
#endif

   protected:
      int BitPosition;                            /**< starting bit position in IPDU */
      int BitSize;                                /**< how many bits does the signal take in IPdu */

};

#endif   // ----- #ifndef _SIGNAL_H_  -----
