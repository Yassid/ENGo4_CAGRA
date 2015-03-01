// $Id: TArtAnlProc.h 813 2011-12-02 12:33:40Z linev $
//-----------------------------------------------------------------------
//       The GSI Online Offline Object Oriented (Go4) Project
//         Experiment Data Processing at EE department, GSI
//-----------------------------------------------------------------------
// Copyright (C) 2000- GSI Helmholtzzentrum für Schwerionenforschung GmbH
//                     Planckstr. 1, 64291 Darmstadt, Germany
// Contact:            http://go4.gsi.de
//-----------------------------------------------------------------------
// This software can be used under the license agreements as stated
// in Go4License.txt file which is part of the distribution.
//-----------------------------------------------------------------------

#ifndef TArtANLPROCESSOR_H
#define TArtANLPROCESSOR_H

#include "TGo4EventProcessor.h"

#include "TArtSortEvent.h"
#include "TGo4PolyCond.h"

#include "TRandom.h"

class TArtF2Param;
class TArtF3Param;
class TArtAnlEvent;

class TArtAnlProc : public TGo4EventProcessor {
   public:
      TArtAnlProc();
      TArtAnlProc(const char * name);
      virtual ~TArtAnlProc();

      virtual Bool_t BuildEvent(TGo4EventElement* dest);      
      TH1              *TPC_PID_Center[4];


      TH1              *F2_UPPAC_Cal_Time_X;
      TH1              *F2_UPPAC_Cal_Time_Y; 
      TH1              *F2_DPPAC_Cal_Time_X;
      TH1              *F2_DPPAC_Cal_Time_Y;

      TH1              *F2_UPPAC_Cal_Position_X;
      TH1              *F2_UPPAC_Cal_Position_Y; 
      TH1              *F2_DPPAC_Cal_Position_X;
      TH1              *F2_DPPAC_Cal_Position_Y;

      TH2              *F2_UPPAC_Pos_Time;
      TH2              *F2_DPPAC_Pos_Time;

      TH2              *F2_UPPAC_Pos_mm;
      TH2              *F2_DPPAC_Pos_mm;

      // 28052014 TETSUYA ADD
      TH1              *F3_UPPAC_Cal_Time_X;
      TH1              *F3_UPPAC_Cal_Time_Y; 
      TH1              *F3_DPPAC_Cal_Time_X;
      TH1              *F3_DPPAC_Cal_Time_Y;

      TH1              *F3_UPPAC_Cal_Position_X;
      TH1              *F3_UPPAC_Cal_Position_Y; 
      TH1              *F3_DPPAC_Cal_Position_X;
      TH1              *F3_DPPAC_Cal_Position_Y;

      TH2              *F3_UPPAC_Pos_Time;
      TH2              *F3_DPPAC_Pos_Time;

      TH2              *F3_UPPAC_Pos_mm;
      TH2              *F3_DPPAC_Pos_mm;
      // -----------------------------
      
      TH2              *Beam_profile_z[9];
      TH2              *Beam_profile_z_cond[9];
      
      TH2              *Beam_profile_z_cond5[9];
      TH2              *Beam_profile_z_cond6[9];
      TH2              *Beam_profile_z_cond7[9];

      TH1              *F2_Sil_Energy;

      TH1              *F2_Scint_TOF;
      
      TH2              *Beam_trckZX;
      TH2              *Beam_trckZY;
      
      TH2              *PID_RF_Scint_cond;
      
      TH1              *RF_Cond;
     
      TArtF2Param      *fF2Param;
      TArtF3Param      *fF3Param; // 28952014 TETSUYA ADD

      TGo4WinCond      *fWinCon;
      
      TGo4PolyCond     *PID_Raw_GATE_Scint;
      
      TRandom          *randomnum;
      
   

   private:
   
   	TH2* MakeH2I_Profile(const char* foldername, 
				int index);

	TH2* MakeH2I_Profile_cond(const char* foldername, 
				int index, int cond);

        TH2* MakeH2I_TPC_ID(const char* foldername, 
				int index);

   ClassDef(TArtAnlProc, 1)
};
#endif //TArtANLPROCESSOR_H
