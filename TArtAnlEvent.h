// $Id: TArtAnlEvent.h 755 2011-05-20 08:04:11Z linev $
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

#ifndef TArtANLEVENT_H
#define TArtANLEVENT_H

#include "TGo4EventElement.h"
#include "TArtSortEvent.h"

class TArtAnlEvent : public TGo4EventElement {
   public:
      TArtAnlEvent() : TGo4EventElement() {}
      TArtAnlEvent(const char* name) : TGo4EventElement(name) {}
      virtual ~TArtAnlEvent() {}

      virtual void  Clear(Option_t *t="");

   
     /* Float_t Hodo_dE_cal_pos[13];
      Float_t Hodo_dE_cal_ToF_L[13];
      Float_t Hodo_dE_cal_ToF_R[13];
      Float_t Hodo_dE_cal_ener[13];

      Float_t Hodo_EONE_cal_pos[16];
      Float_t Hodo_EONE_cal_ToF_L[16];
      Float_t Hodo_EONE_cal_ToF_R[16]; 
      Float_t Hodo_EONE_cal_ener[16];

      Float_t Hodo_ETWO_cal_pos[13];
      Float_t Hodo_ETWO_cal_ToF_L[13];
      Float_t Hodo_ETWO_cal_ToF_R[13]; 
      Float_t Hodo_ETWO_cal_ener[13];
      
      Int_t HODO_dE_Hit;
      Int_t HODO_E2_Hit;
      Int_t HODO_E1_Hit;
      
      Int_t HODO_dE5_Hit;
      Int_t HODO_dE6_Hit;
      Int_t HODO_dE7_Hit;*/
      

      Float_t F2UPPAC_Cal_Pos_X_ns;
      Float_t F2UPPAC_Cal_Pos_Y_ns;
      Float_t F2DPPAC_Cal_Pos_X_ns;
      Float_t F2DPPAC_Cal_Pos_Y_ns;
      
      Float_t F2UPPAC_Cal_Pos_X_mm;
      Float_t F2UPPAC_Cal_Pos_Y_mm;
      Float_t F2DPPAC_Cal_Pos_X_mm;
      Float_t F2DPPAC_Cal_Pos_Y_mm; 

      // 28052014 TETSUYA ADD
      Float_t F3UPPAC_Cal_Pos_X_ns;
      Float_t F3UPPAC_Cal_Pos_Y_ns;
      Float_t F3DPPAC_Cal_Pos_X_ns;
      Float_t F3DPPAC_Cal_Pos_Y_ns;
      
      Float_t F3UPPAC_Cal_Pos_X_mm;
      Float_t F3UPPAC_Cal_Pos_Y_mm;
      Float_t F3DPPAC_Cal_Pos_X_mm;
      Float_t F3DPPAC_Cal_Pos_Y_mm; 

      Float_t Beam_prof_x[11];
      Float_t Beam_prof_y[11]; 
      
      Float_t dr_ang;
      Float_t Beam_trck_X;
      Float_t Beam_trck_Y;  


      Float_t F2Sil_Energy;

      Float_t F2Scint_Cal_ToF;
      
      

      

   ClassDef(TArtAnlEvent,1)
};
#endif //TArtANLEVENT_H



