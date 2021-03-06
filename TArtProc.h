#ifndef TUNPACKPROCESSOR_H
#define TUNPACKPROCESSOR_H

#include "TGo4EventProcessor.h"

class TArtEvent;
//class TArtParam;
class TArtRawEventObject;

class TArtProc : public TGo4EventProcessor {
   public:
      TArtProc() ;
      TArtProc(const char* name);
      virtual ~TArtProc() ;
      // event processing function, default name
      Bool_t BuildEvent(TGo4EventElement* target);
      Bool_t FillHistograms(TArtRawEventObject* event);

 private:
      TH2I          *fc1x2;
      TH1           *fHis1;
      TH1F          *fADCHis[16];
      TH1I          *fHisDID;
      TH1I          *fHisADC;
      TGo4WinCond   *fcHis1;
      // TArtParam     *fPar1;
      Float_t        f1[8];
      Float_t        f2[8];
      Int_t          mhitl[128];
      Int_t          mhitt[128];

      TH1	     *fCoin;

     

      /* int geo;
      int ch;
      int val; 
      int det;
      int mod;*/
      


      TH1* MakeH1ISeries(const char* foldername,
                          Int_t seriesnumber,
                          Int_t crate,
                          Int_t number,
                          Bool_t remove);

                      
      TGo4Picture* MakeSeriesPicture(const char* foldername,
                                     Int_t seriesnumber,
                                     Bool_t remove);              
      
      
      TGo4Picture* MakeSeriesPicturevme01(const char* foldername,
					 Int_t seriesnumber,
					 Bool_t remove);              
    // TH1            *hsva02_4[128];      //!


      TH1            *hTrigger;  // TODO Which module will define trigger
      // E390 Yassid 220813 14:48  EN Course F2 Crate 21 slots
     /* TH1            *hvmi01_0[32];      //!
      TH1            *hvmi01_1[32];      //!
      TH1            *hvmi01_2[32];      //!
      TH1            *hvmi01_3[32];      //!
      TH1            *hvmi01_4[32];      //!
      TH1            *hvmi01_5[128];      // Special for v1190
      TH1            *hvmi01_6[32]; 
      TH1            *hvmi01_7[32];
      TH1            *hvmi01_8[32];      //!
      TH1            *hvmi01_9[32];      //!
      TH1            *hvmi01_10[32];
      TH1            *hvmi01_11[32];      //!
      TH1            *hvmi01_12[32];
      TH1            *hvmi01_13[32];      //!
      TH1            *hvmi01_14[32];
      TH1            *hvmi01_15[32];      //!
      TH1            *hvmi01_16[32];      //!
      TH1            *hvmi01_17[32];      //!
      TH1            *hvmi01_18[32];      //!
      TH1            *hvmi01_19[32];      //!
      TH1            *hvmi01_20[32];      //!*/


      // E390 Yassid 220813 14:52  EN Course F2 Hodoscope Crate 21 slots
      /*TH1            *hsva01_0[32];      //!
      TH1            *hsva01_1[128];      //! Special for v1190
      TH1            *hsva01_2[32];      //!
      TH1            *hsva01_3[32];      //!
      TH1            *hsva01_4[32];      //!
      TH1            *hsva01_5[32];      //
      TH1            *hsva01_6[32]; 
      TH1            *hsva01_7[32];
      TH1            *hsva01_8[32];      //!
      TH1            *hsva01_9[32];      //!
      TH1            *hsva01_10[32];*/
      TH1            *hsva01_11[32];      //!  // Yassid 01062014 SSD detectors located on F3 crate
    /*  TH1            *hsva01_12[32];
      TH1            *hsva01_13[32];      //!
      TH1            *hsva01_14[32];
      TH1            *hsva01_15[32];      //!
      TH1            *hsva01_16[32];      //!
      TH1            *hsva01_17[32];      //!
      TH1            *hsva01_18[32];      //!
      TH1            *hsva01_19[32];      //!
      TH1            *hsva01_20[32];      //!*/


      TH1            *hv7768_0[32];      //!
      TH1            *hv7768_1[32];      //!
      TH1            *hv7768_2[32];      //!
      TH1            *hv7768_3[32];      //!
      TH1            *hv7768_4[32];      //!
      TH1            *hv7768_5[32];      // LUPO
      TH1            *hv7768_6[32]; 
      TH1            *hv7768_7[32];
      TH1            *hv7768_8[32];      //!
      TH1            *hv7768_9[32];      //!
      TH1            *hv7768_10[32];
      TH1            *hv7768_11[32];      //!
      TH1            *hv7768_12[32];
      TH1            *hv7768_13[32];      //!
      TH1            *hv7768_14[32];
      TH1            *hv7768_15[128];      // Special for v1190
      TH1            *hv7768_16[128];      //!
      TH1            *hv7768_17[32];      //!
      TH1            *hv7768_18[32];      //!
      TH1            *hv7768_19[32];      //!
      TH1            *hv7768_20[32];      //!

       // E390 Yassid 220813 14:57  EN Course F1 Crate 7 slots
 
     
     
      //TH1            *hsva02_3[128];      //!
     // TH1            *hsva02_4[128];      //!
     // TH1            *hsva02_6[32];
     
      
     
      

   ClassDef(TArtProc,1)
};
#endif //TUNPACKPROCESSOR_H


//----------------------------END OF GO4 SOURCE FILE ---------------------
