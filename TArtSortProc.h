// $Id: TArtSortProc.h 813 2011-12-02 12:33:40Z linev $
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
#ifndef TArtSORTPROCESSOR_H
#define TArtSORTPROCESSOR_H


#include <TH1.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <TSystem.h>
#include <vector>
//#include "TArtEvent
#include "TGo4EventProcessor.h"
#include "TArtUnpackEvent.h"
//class TArtParam;
#include "segidlist.h"



class TArtSortEvent;

class TArtSortProc : public TGo4EventProcessor {
   public:
      TArtSortProc();
      TArtSortProc(const char * name);
      virtual ~TArtSortProc();
      
      virtual Bool_t BuildEvent(TGo4EventElement* dest);
        int ReadParameters(char* filename);
        int Put2Array(char*, int*,int);
   int Put2Array(char*, double*,int);
         char* ltrim(char*);
   char* rtrim(char*);
   char* trim(char*);
   ifstream fi;

  void SetPosition(int, int, int, int, int, int Anode = 0);
  void SetPosition(int , int , int* );
  void SetPosition(int , int* , int , int* );
  double GetX_Time(int no){return posXns[no];};
  double GetY_Time(int no){return posYns[no];};
  double GetX_Position(int no){return posXmm[no];};
  double GetY_Position(int no){return posYmm[no];};
  double GetF2_aX_mrad();
  double GetF2_aY_mrad();
  double GetF3_aX_mrad();
  double GetF3_aY_mrad();
  double GetF2ExtrapolationX(double atZ);
  double GetF2ExtrapolationY(double atZ);
  double GetF3ExtrapolationX(double atZ);
  double GetF3ExtrapolationY(double atZ);
      // TH2              *F1_fiber_id;
     // TH2              *F1_Q_corr[16];
      
      TH1              *F2_u_ppac_l_t;
      TH1              *F2_u_ppac_d_t;
      TH1              *F2_u_ppac_r_t;
      TH1              *F2_u_ppac_u_t;
      TH1              *F2_u_ppac_a_t;
         
      TH1              *F2_d_ppac_l_t;
      TH1              *F2_d_ppac_d_t;
      TH1              *F2_d_ppac_r_t;
      TH1              *F2_d_ppac_u_t;
      TH1              *F2_d_ppac_a_t;

      TH1              *F3_u_ppac_l_t;
      TH1              *F3_u_ppac_d_t;
      TH1              *F3_u_ppac_r_t;
      TH1              *F3_u_ppac_u_t;
      TH1              *F3_u_ppac_a_t;
      // TETSUYA e407  28052014 ADD
      TH1              *F3_d_ppac_l_t;
      TH1              *F3_d_ppac_d_t;
      TH1              *F3_d_ppac_r_t;
      TH1              *F3_d_ppac_u_t;
      TH1              *F3_d_ppac_a_t;

      //Yagi  28022015 Add
      TH1              *F2_u_ppac_l_tns;
      TH1              *F2_u_ppac_d_tns;
      TH1              *F2_u_ppac_r_tns;
      TH1              *F2_u_ppac_u_tns;
      TH1              *F2_u_ppac_a_tns;
         
      TH1              *F2_d_ppac_l_tns;
      TH1              *F2_d_ppac_d_tns;
      TH1              *F2_d_ppac_r_tns;
      TH1              *F2_d_ppac_u_tns;
      TH1              *F2_d_ppac_a_tns;

      TH1              *F3_u_ppac_l_tns;
      TH1              *F3_u_ppac_d_tns;
      TH1              *F3_u_ppac_r_tns;
      TH1              *F3_u_ppac_u_tns;
      TH1              *F3_u_ppac_a_tns;

      TH1              *F3_d_ppac_l_tns;
      TH1              *F3_d_ppac_d_tns;
      TH1              *F3_d_ppac_r_tns;
      TH1              *F3_d_ppac_u_tns;
      TH1              *F3_d_ppac_a_tns;
     
      TH1              *F2_u_ppac_Xmm;
      TH1              *F2_d_ppac_Xmm;
      TH1              *F2_u_ppac_Ymm;
      TH1              *F2_d_ppac_Ymm;

  
      TH1              *F3_u_ppac_Xmm;
      TH1              *F3_d_ppac_Xmm;
      TH1              *F3_u_ppac_Ymm;
      TH1              *F3_d_ppac_Ymm;


      TH1              *F2_ppac_aXmrad;
      TH1              *F2_ppac_aYmrad;

  
      TH1              *F3_ppac_aXmrad;
      TH1              *F3_ppac_aYmrad;

      TH2              *F2_u_ppac_XYmm;
      TH2              *F2_d_ppac_XYmm;
      TH2              *F2_Viewer_XYmm;
      TH2              *F2_X_vs_aX;
      TH2              *F2_Y_vs_aY;
      TH2              *F2ExtrapolationZmm_Xmm;
      TH2              *F2ExtrapolationZmm_Ymm;
      TH2              *F3_u_ppac_XYmm;
      TH2              *F3_d_ppac_XYmm;
      TH2              *F3_target_XYmm;
      TH2              *F3_X_vs_aX;
      TH2              *F3_Y_vs_aY;
      TH2              *F3ExtrapolationZmm_Xmm;
      TH2              *F3ExtrapolationZmm_Ymm;
     

      // ------------------------------      

      TH2              *F2_u_ppac_pos;
      TH2              *F2_d_ppac_pos;
      
      TH2              *F3_u_ppac_pos;
      TH2              *F3_d_ppac_pos; // TETSUYA e407  28052014 ADD

      TH2              *F2_u_ppac_pos_cond;
      TH2              *F2_d_ppac_pos_cond;
      
      TH2              *F3_u_ppac_pos_cond;
      TH2              *F3_d_ppac_pos_cond; 

      TH1              *F2_u_ppac_pos_X;
      TH1              *F2_d_ppac_pos_X;

      TH1              *F3_u_ppac_pos_X;  
      TH1              *F3_d_ppac_pos_X; // TETSUYA e407  28052014 ADD

      TH1              *F2_u_ppac_pos_Y;
      TH1              *F2_d_ppac_pos_Y;

      TH1              *F3_u_ppac_pos_Y;
      TH1              *F3_d_ppac_pos_Y; // TETSUYA e407  28052014 ADD

     
        
    /*  TH1              *F2_Sil;
      TH1              *F3_Sil;  //TETSUYA e407  28052014 ADD CHK

      TH1              *F2_Sci_q;
      TH1              *F2_Sci_t;
      
      TH2              *F2_PID_Raw_Si;
      TH2              *F2_PID_Raw_Scint;

      TH1              *F2_RaF;
      TH1              *F2_Tref_TDC;
      TH1	       *F2_PPACT_Trigger;*/

      // TETSUYA e407  28052014 ADD
   //   TH1              *F2_plastic;
  //    TH1              *F3_plastic_l;
  ///    TH1              *F3_plastic_r;
      
      TH1              *Rf;
   //   TH1              *F2_plastic_t;
   //   TH1              *F3_plastic_l_t;
   //   TH1              *F3_plastic_r_t;

   //   TH1              *F2_ssd;
   //   TH1              *F3_ssd;

    //  TH2              *F3_PID_Raw_Si;
    // TH2              *F3_PID_Raw_Scint;      
     // TH2              *PID_Rf_F2Si;
     // TH2              *PID_Rf_F3Si;


      // ------------------------------      
      
      // TETSUYA e407  28052014 ADD
      //      TH2              *F3_PID_Scint_Si;
      // ------------------------------      
      
      TGo4PolyCond     *PID_Raw_GATE;

 private:
      TH1* MakeH1I_Hodo(const char* foldername, 
			int layer,int position,int var, int index,
                        const char* xtitle = "channels");
      
      TH1* MakeH1I_DSSD(const char* foldername, 
			int position,int layer,int strip,
			const char* xtitle);
      
      TH1* MakeH1I_CSI(const char* foldername, 
		       int csiarray,int csinumber);
      
      TH1* MakeH1I_SSD(const char* foldername, 
		       int ssdnumber);
      
      TH1* MakeH1I_TPCSi(const char* foldername, 
			 int side,int position);
      
      TH1* MakeH1I_TPCCsI(const char* foldername, 
			  int position,int number,int side);
        int traw[5][5]; 
         double tcal[5][5];
   double ch2ns[5][5];
   double ch2qdc[5][5];
   double qdcped[5][5];
   double ns2mm[5][2];
   double in_offset[5][2];
   double out_offset[5][2];
   double geo_offset[5][2];
   double offset[5][2];
   double posXmm[5],posYmm[5];
   double posXns[5],posYns[5];
   double F2distance,F3distance;
   double aX_mrad,aY_mrad;

   int flagprm;
        char* GetNextLine(char s ='#' );
      ClassDef(TArtSortProc, 1)
	};
#endif //TArtSORTPROCESSOR_H
