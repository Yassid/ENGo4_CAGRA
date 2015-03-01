// $Id: TArtSortProc.cxx 933 2013-01-29 15:27:58Z linev $
//-----------------------------------------------------------------------
//       The GSI Online Offline Object Oriented (Go4) Project
//         Experiment Data Processing at EE department, GSI
//-----------------------------------------------------------------------
// Copyright (C) 2000- GSI Helmholtzzentrum f�r Schwerionenforschung GmbH
//                     Planckstr. 1, 64291 Darmstadt, Germany
// Contact:            http://go4.gsi.de
//-----------------------------------------------------------------------
// This software can be used under the license agreements as stated
// in Go4License.txt file which is part of the distribution.
//-----------------------------------------------------------------------

#include "TArtSortProc.h"

#include <math.h>

#include "TH1.h"
#include "TH2.h"
#include "TROOT.h"

#include "TGo4WinCond.h"
#include "TGo4PolyCond.h"
#include "TGo4Analysis.h"

#include "TArtSortEvent.h"
#include "TArtUnpackEvent.h"
//#include "TArtParam.h"

//-----------------------------------------------------------
TArtSortProc::TArtSortProc() :
   TGo4EventProcessor(),
   F2_u_ppac_l_t(0), F2_u_ppac_d_t(0), F2_u_ppac_r_t(0),F2_u_ppac_u_t(0), F2_u_ppac_a_t(0),
   F2_d_ppac_l_t(0), F2_d_ppac_d_t(0), F2_d_ppac_r_t(0),F2_d_ppac_u_t(0), F2_d_ppac_a_t(0),
   F3_u_ppac_l_t(0), F3_u_ppac_d_t(0), F3_u_ppac_r_t(0),F3_u_ppac_u_t(0), F3_u_ppac_a_t(0),
   F3_d_ppac_l_t(0), F3_d_ppac_d_t(0), F3_d_ppac_r_t(0),F3_d_ppac_u_t(0), F3_d_ppac_a_t(0),
   F2_u_ppac_pos(0),F2_d_ppac_pos(0),F2_u_ppac_pos_X(0),F2_d_ppac_pos_X(0), 
   F3_u_ppac_pos(0),F3_d_ppac_pos(0),F3_u_ppac_pos_X(0),F3_d_ppac_pos_X(0), 
   F2_u_ppac_pos_Y(0),F2_d_ppac_pos_Y(0),F3_u_ppac_pos_Y(0),F3_d_ppac_pos_Y(0)
   //F2_plastic(0),F3_plastic_l(0),F3_plastic_r(0),Rf(0),F2_plastic_t(0),F3_plastic_l_t(0),F3_plastic_r_t(0)
{
  /*
  char fn[20];
  sprintf(fn,"ppac.prm");
  flagprm = ReadParameters(fn);
  */
}

//-----------------------------------------------------------
TArtSortProc::TArtSortProc(const char* name) :
   TGo4EventProcessor(name),
 
   F2_u_ppac_l_t(0), F2_u_ppac_d_t(0), F2_u_ppac_r_t(0),F2_u_ppac_u_t(0), F2_u_ppac_a_t(0),
   F2_d_ppac_l_t(0), F2_d_ppac_d_t(0), F2_d_ppac_r_t(0),F2_d_ppac_u_t(0), F2_d_ppac_a_t(0),
   F3_u_ppac_l_t(0), F3_u_ppac_d_t(0), F3_u_ppac_r_t(0),F3_u_ppac_u_t(0), F3_u_ppac_a_t(0),
   F3_d_ppac_l_t(0), F3_d_ppac_d_t(0), F3_d_ppac_r_t(0),F3_d_ppac_u_t(0), F3_d_ppac_a_t(0),
   F2_u_ppac_pos(0),F2_d_ppac_pos(0),F2_u_ppac_pos_X(0),F2_d_ppac_pos_X(0), 
   F3_u_ppac_pos(0),F3_d_ppac_pos(0),F3_u_ppac_pos_X(0),F3_d_ppac_pos_X(0), 
   F2_u_ppac_pos_Y(0),F2_d_ppac_pos_Y(0),F3_u_ppac_pos_Y(0),F3_d_ppac_pos_Y(0)
  // F2_plastic(0),F3_plastic_l(0),F3_plastic_r(0),Rf(0),F2_plastic_t(0),F3_plastic_l_t(0),F3_plastic_r_t(0)
{
   TGo4Log::Info("TArtSortProc: Create");
   //// init user analysis objects:
      F2distance=482;F3distance=500;
 char fn[20];
  sprintf(fn,"ppac.prm");
  //cout<<fn<<endl;
  flagprm = ReadParameters(fn);
  
   // Yassid 28092013 19:45 PPAC Histograms for v1190
   F2_u_ppac_l_t     = MakeTH1('I', "Sort/F2/PPAC/F2_U_PPAC_L", "F2_Upstream_PPAC_Left_Time", 4000, 1., 50000.);
   F2_u_ppac_d_t     = MakeTH1('I', "Sort/F2/PPAC/F2_U_PPAC_D", "F2_Upstream_PPAC_Down_Time", 4000, 1., 50000.);
   F2_u_ppac_r_t     = MakeTH1('I', "Sort/F2/PPAC/F2_U_PPAC_R", "F2_Upstream_PPAC_Right_Time", 4000, 1., 50000.);
   F2_u_ppac_u_t     = MakeTH1('I', "Sort/F2/PPAC/F2_U_PPAC_U", "F2_Upstream_PPAC_Up_Time", 4000, 1., 50000.); 
   F2_u_ppac_a_t     = MakeTH1('I', "Sort/F2/PPAC/F2_U_PPAC_A", "F2_Upstream_PPAC_Anode_Time", 4000, 1., 50000.);
   F2_d_ppac_l_t     = MakeTH1('I', "Sort/F2/PPAC/F2_D_PPAC_L", "F2_Downstream_PPAC_Left_Time", 4000, 1., 50000.);
   F2_d_ppac_d_t     = MakeTH1('I', "Sort/F2/PPAC/F2_D_PPAC_D", "F2_Downstream_PPAC_Down_Time", 4000, 1., 50000.);
   F2_d_ppac_r_t     = MakeTH1('I', "Sort/F2/PPAC/F2_D_PPAC_R", "F2_Downstream_PPAC_Right_Time", 4000, 1., 50000.);
   F2_d_ppac_u_t     = MakeTH1('I', "Sort/F2/PPAC/F2_D_PPAC_U", "F2_Downstream_PPAC_Up_Time", 4000, 1., 50000.); 
   F2_d_ppac_a_t     = MakeTH1('I', "Sort/F2/PPAC/F2_D_PPAC_A", "F2_Downstream_PPAC_Anode_Time", 4000, 1., 50000.);
   // Yassid E419 06112013 17:05 Adding F3 Upstream PPAC for v1190 5us range
   F3_u_ppac_l_t     = MakeTH1('I', "Sort/F3/PPAC/F3_U_PPAC_L", "F3_Upstream_PPAC_Left_Time", 4000, 1., 50000.);
   F3_u_ppac_d_t     = MakeTH1('I', "Sort/F3/PPAC/F3_U_PPAC_D", "F3_Upstream_PPAC_Down_Time", 4000, 1., 50000.);
   F3_u_ppac_r_t     = MakeTH1('I', "Sort/F3/PPAC/F3_U_PPAC_R", "F3_Upstream_PPAC_Right_Time", 4000, 1., 50000.);
   F3_u_ppac_u_t     = MakeTH1('I', "Sort/F3/PPAC/F3_U_PPAC_U", "F3_Upstream_PPAC_Up_Time", 4000, 1., 50000.); 
   F3_u_ppac_a_t     = MakeTH1('I', "Sort/F3/PPAC/F3_U_PPAC_A", "F3_Upstream_PPAC_Anode_Time", 4000, 1., 50000.); 
   
// TETSUYA e407 28052014 ADD
   F3_d_ppac_l_t     = MakeTH1('I', "Sort/F3/PPAC/F3_D_PPAC_L", "F3_Downstream_PPAC_Left_Time", 4000, 1., 50000.);
   F3_d_ppac_d_t     = MakeTH1('I', "Sort/F3/PPAC/F3_D_PPAC_D", "F3_Downstream_PPAC_Down_Time", 4000, 1., 50000.);
   F3_d_ppac_r_t     = MakeTH1('I', "Sort/F3/PPAC/F3_D_PPAC_R", "F3_Downstream_PPAC_Right_Time", 4000, 1., 50000.);
   F3_d_ppac_u_t     = MakeTH1('I', "Sort/F3/PPAC/F3_D_PPAC_U", "F3_Downstream_PPAC_Up_Time", 4000, 1., 50000.); 
   F3_d_ppac_a_t     = MakeTH1('I', "Sort/F3/PPAC/F3_D_PPAC_A", "F3_Downstream_PPAC_Anode_Time", 4000, 1., 50000.);

   F2_u_ppac_pos     = MakeTH2('I', "Sort/F2/PPAC/F2_U_POS","F2_Upstream_PPAC_position",1000, -2000., 2000., 1000, -2000., 2000.);
   F2_d_ppac_pos     = MakeTH2('I', "Sort/F2/PPAC/F2_D_POS","F2_Downstream_PPAC_position",1000, -2000., 2000., 1000, -2000., 2000.);
   F3_u_ppac_pos     = MakeTH2('I', "Sort/F3/PPAC/F3_U_POS","F3_Upstream_PPAC_position",1000, -2000., 2000., 1000, -2000., 2000.);// TETSUYA e407  28052014 ADD
   F3_d_ppac_pos     = MakeTH2('I', "Sort/F3/PPAC/F3_D_POS","F3_Downstream_PPAC_position",1000, -2000., 2000., 1000, -2000., 2000.);


   F2_u_ppac_pos_cond     = MakeTH2('I', "Sort/F2/PPAC/F2_U_POS_cond","F2_Upstream_PPAC_position_cond",1000, -2000., 2000., 1000, -2000., 2000.);
   F2_d_ppac_pos_cond     = MakeTH2('I', "Sort/F2/PPAC/F2_D_POS_cond","F2_Downstream_PPAC_position_cond",1000, -2000., 2000., 1000, -2000., 2000.);
   F3_u_ppac_pos_cond     = MakeTH2('I', "Sort/F3/PPAC/F3_U_POS_cond","F3_Upstream_PPAC_position_cond",1000, -2000., 2000., 1000, -2000., 2000.);//
   F3_d_ppac_pos_cond     = MakeTH2('I', "Sort/F3/PPAC/F3_D_POS_cond","F3_Downstream_PPAC_position_cond",1000, -2000., 2000., 1000, -2000., 2000.);


   F2_u_ppac_pos_X  =  MakeTH1('I', "Sort/F2/PPAC/F2_U_POS_X","F2_Upstream_PPAC_position_X",1000, -2000., 2000.);   
   F2_d_ppac_pos_X  =  MakeTH1('I', "Sort/F2/PPAC/F2_D_POS_X","F2_Downstream_PPAC_position_X",1000, -2000., 2000.);
   F3_u_ppac_pos_X  =  MakeTH1('I', "Sort/F3/PPAC/F3_U_POS_X","F3_Upstream_PPAC_position_X",1000, -2000., 2000.);  
   F3_d_ppac_pos_X  =  MakeTH1('I', "Sort/F3/PPAC/F3_D_POS_X","F3_Downstream_PPAC_position_X",1000, -2000., 2000.);
   // TETSUYA e407  28052014 ADD

   F2_u_ppac_pos_Y =   MakeTH1('I', "Sort/F2/PPAC/F2_U_POS_Y","F2_Upstream_PPAC_position_Y",1000, -2000., 2000.);
   F2_d_ppac_pos_Y =   MakeTH1('I', "Sort/F2/PPAC/F2_D_POS_Y","F2_Downstream_PPAC_position_Y",1000, -2000., 2000.); 
   F3_u_ppac_pos_Y =   MakeTH1('I', "Sort/F3/PPAC/F3_U_POS_Y","F3_Upstream_PPAC_position_Y",1000, -2000., 2000.);
   F3_d_ppac_pos_Y =   MakeTH1('I', "Sort/F3/PPAC/F3_D_POS_Y","F3_Downstream_PPAC_position_Y",1000, -2000., 2000.);

   //Yagi add
   ////////D1/////////////
   F2_u_ppac_l_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_l_tns","F2_u_ppac_l_tns",2000, -2000., 2000.);
   F2_u_ppac_d_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_d_tns","F2_u_ppac_d_tns",2000, -2000., 2000.);
   F2_u_ppac_r_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_r_tns","F2_u_ppac_r_tns",2000, -2000., 2000.);
   F2_u_ppac_u_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_u_tns","F2_u_ppac_u_tns",2000, -2000., 2000.);
   F2_u_ppac_a_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_a_tns","F2_u_ppac_a_tns",2000, -2000., 2000.);

   F2_d_ppac_l_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_l_tns","F2_d_ppac_l_tns",2000, -2000., 2000.);
   F2_d_ppac_d_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_d_tns","F2_d_ppac_d_tns",2000, -2000., 2000.);
   F2_d_ppac_r_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_r_tns","F2_d_ppac_r_tns",2000, -2000., 2000.);
   F2_d_ppac_u_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_u_tns","F2_d_ppac_u_tns",2000, -2000., 2000.);
   F2_d_ppac_a_tns =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_a_tns","F2_d_ppac_a_tns",2000, -2000., 2000.);

   F3_u_ppac_l_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_l_tns","F3_u_ppac_l_tns",2000, -2000., 2000.);
   F3_u_ppac_d_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_d_tns","F3_u_ppac_d_tns",2000, -2000., 2000.);
   F3_u_ppac_r_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_r_tns","F3_u_ppac_r_tns",2000, -2000., 2000.);
   F3_u_ppac_u_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_u_tns","F3_u_ppac_u_tns",2000, -2000., 2000.);
   F3_u_ppac_a_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_a_tns","F3_u_ppac_a_tns",2000, -2000., 2000.);

   F3_d_ppac_l_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_l_tns","F3_d_ppac_l_tns",2000, -2000., 2000.);
   F3_d_ppac_d_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_d_tns","F3_d_ppac_d_tns",2000, -2000., 2000.);
   F3_d_ppac_r_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_r_tns","F3_d_ppac_r_tns",2000, -2000., 2000.);
   F3_d_ppac_u_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_u_tns","F3_d_ppac_u_tns",2000, -2000., 2000.);
   F3_d_ppac_a_tns =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_a_tns","F3_d_ppac_a_tns",2000, -2000., 2000.);



   F2_u_ppac_Xmm =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_Xmm","F2_u_ppac_Xmm",240, -60., 60.);
   F2_d_ppac_Xmm =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_Xmm","F2_d_ppac_Xmm",240, -60., 60.);

   F2_u_ppac_Ymm =   MakeTH1('F', "Sort/F2/PPAC/F2_u_ppac_Ymm","F2_u_ppac_Ymm",240, -60., 60.);
   F2_d_ppac_Ymm =   MakeTH1('F', "Sort/F2/PPAC/F2_d_ppac_Ymm","F2_d_ppac_Ymm",240, -60., 60.);

   F3_u_ppac_Xmm =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_Xmm","F3_u_ppac_Xmm",240, -60., 60.);
   F3_d_ppac_Xmm =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_Xmm","F3_d_ppac_Xmm",240, -60., 60.);
   F3_u_ppac_Ymm =   MakeTH1('F', "Sort/F3/PPAC/F3_u_ppac_Ymm","F3_u_ppac_Ymm",240, -60., 60.);
   F3_d_ppac_Ymm =   MakeTH1('F', "Sort/F3/PPAC/F3_d_ppac_Ymm","F3_d_ppac_Ymm",240, -60., 60.);


   F2_ppac_aXmrad =   MakeTH1('F', "Sort/F2/PPAC/F2_ppac_aXmrad","F2_ppac_aXmrad",240, -60., 60.);

   F2_ppac_aYmrad =   MakeTH1('F', "Sort/F2/PPAC/F2_ppac_aYmrad","F2_ppac_aYmrad",240, -60., 60.);

   F3_ppac_aXmrad =   MakeTH1('F', "Sort/F3/PPAC/F3_ppac_aXmrad","F3_ppac_aXmrad",240, -60., 60.);
   F3_ppac_aYmrad =   MakeTH1('F', "Sort/F3/PPAC/F3_ppac_aYmrad","F3_ppac_aYmrad",240, -60., 60.);

   ///////////D2/////////////

   F2_u_ppac_XYmm    = MakeTH2('F', "Sort/F2/PPAC/F2_u_ppac_XYmm"," F2_u_ppac_XYmm ",240, -60., 60.,240, -60., 60.);
   F2_d_ppac_XYmm    = MakeTH2('F', "Sort/F2/PPAC/F2_d_ppac_XYmm"," F2_d_ppac_XYmm ",240, -60., 60.,240, -60., 60.);
   F2_Viewer_XYmm    = MakeTH2('F', "Sort/F2/PPAC/F2_Viewer_XYmm"," F2_Viewer_XYmm ",240, -60., 60.,240, -60., 60.);
   F2_X_vs_aX    = MakeTH2('F', "Sort/F2/PPAC/F2_X_vs_aX"," F2_X_vs_aX ",240, -60., 60.,240, -60., 60.);
   F2_Y_vs_aY    = MakeTH2('F', "Sort/F2/PPAC/F2_Y_vs_aY"," F2_Y_vs_aY ",240, -60., 60.,240, -60., 60.);
  F2ExtrapolationZmm_Xmm    = MakeTH2('F', "Sort/F2/PPAC/F2ExtrapolationXmm_Zmm"," F2ExtrapolationXmm_Zmm ",1000, -500., 2000.,240, -60., 60.);
  F2ExtrapolationZmm_Ymm    = MakeTH2('F', "Sort/F2/PPAC/F2ExtrapolationYmm_Zmm"," F2ExtrapolationYmm_Zmm ",1000, -500., 2000.,240, -60., 60.);

   F3_u_ppac_XYmm    = MakeTH2('F', "Sort/F3/PPAC/F3_u_ppac_XYmm"," F3_u_ppac_XYmm ",240, -60., 60.,240, -60., 60.);
   F3_d_ppac_XYmm    = MakeTH2('F', "Sort/F3/PPAC/F3_d_ppac_XYmm"," F3_d_ppac_XYmm ",240, -60., 60.,240, -60., 60.);
   F3_target_XYmm    = MakeTH2('F', "Sort/F3/PPAC/F3_target_XYmm"," F3_target_XYmm ",240, -60., 60.,240, -60., 60.);
   F3_X_vs_aX    = MakeTH2('F', "Sort/F3/PPAC/F3_X_vs_aX"," F3_X_vs_aX ",240, -60., 60.,240, -60., 60.);
   F3_Y_vs_aY    = MakeTH2('F', "Sort/F3/PPAC/F3_Y_vs_aY"," F3_Y_vs_aY ",240, -60., 60.,240, -60., 60.);
 F3ExtrapolationZmm_Xmm    = MakeTH2('F', "Sort/F3/PPAC/F3ExtrapolationZmm_Xmm"," F3ExtrapolationZmm_Xmm ",1000, -500., 2000.,240, -60., 60.);
  F3ExtrapolationZmm_Ymm    = MakeTH2('F', "Sort/F3/PPAC/F3ExtrapolationZmm_Ymm"," F3ExtrapolationZmm_Ymm ",1000, -500., 2000.,240, -60., 60.);
 

   // TETSUYA e407  28052014 ADD     

   // TETSUYA e407  30052014 ADD
   //F2_plastic   = MakeTH1('I', "Sort/F2/F2_PLASTIC","F2_Upstream_PLASTIC_QDC_INFO",1000, 1., 4096.);
   //F3_plastic_l = MakeTH1('I', "Sort/F3/F3_PLASTIC_L","F3_Upstream_PLASTIC_QDC_INFO",1000, 1., 4096.);
   //F3_plastic_r = MakeTH1('I', "Sort/F3/F3_PLASTIC_R","F3_Upstream_PLASTIC_QDC_INFO",1000, 1., 4096.);
   //F2_ssd   = MakeTH1('I', "Sort/F2/F2_SSD","F2_SSD_ENERGY",1000, 1., 4096.);
   //F3_ssd   = MakeTH1('I', "Sort/F3/F3_SSD","F3_SSD_ENERGY",1000, 1., 4096.);
   
   Rf             = MakeTH1('I', "Sort/F2/RF_SIGNAL","F2_RF_SIGNAL_INFO",4000, 1., 50000.);
   //F2_plastic_t   = MakeTH1('I', "Sort/F2/F2_PLASTIC_T","F2_Upstream_PLASTIC_TDC_INFO",4000, 1., 50000.);
   //F3_plastic_l_t = MakeTH1('I', "Sort/F3/F3_PLASTIC_L_T","F3_Upstream_PLASTIC_TDC_INFO",4000, 1., 50000.);
   //F3_plastic_r_t = MakeTH1('I', "Sort/F3/F3_PLASTIC_R_T","F3_Upstream_PLASTIC_TDC_INFO",4000, 1., 50000.);

   //F3_PID_Raw_Si     =  MakeTH2('I', "Sort/F3/F3_PID_Raw_Si","F3_PID_Raw_Si",100, 46000., 46500.,1000,1., 4096.);      
   //PID_Rf_F2Si     =  MakeTH2('I', "Sort/PID/PID_Rf_F2Si","PID_Rf_F2Si",1000, -24000,-20000 ,1000,0., 4096.);      
  // PID_Rf_F3Si     =  MakeTH2('I', "Sort/PID/PID_Rf_F3Si","PID_Rf_F3Si",1000, -24000, -20000,1000,0., 4096.);      
  // F3_PID_Raw_Scint  =  MakeTH2('I', "Sort/F3/F3_PID_Raw_Scint","F3_PID_Raw_Scint",100, 46000., 46500., 1000,1.,4096.); 
   
   //------------------------------------------
   
   //F2_Sil            =  MakeTH1('I', "Sort/F2/F2_Sil", "F2_Silicon", 4096, 1., 4096.);
  // F3_Sil            =  MakeTH1('I', "Sort/F3/F3_Sil", "F3_Silicon", 4096, 1., 4096.);

  // F2_Sci_q          =  MakeTH1('I', "Sort/F2/F2_Sci_Q", "F2_Scintillator_Charge", 4096, 1., 4096.);
 //  F2_Sci_t          =  MakeTH1('I', "Sort/F2/F2_Sci_T", "F2_Scintillator_time", 4096, 1., 4096.);
   
  // F2_RaF            =  MakeTH1('I', "Sort/F2/F2_RaF", "F2_Radiofrequency", 50000, 1., 50000.);
  // F2_Tref_TDC       =  MakeTH1('I', "Sort/F2/F2_Tref_TDC", "F2_Tref_TDC_v1190", 4000, 1., 50000.);
   
 // F2_PID_Raw_Si     =  MakeTH2('I', "Sort/F2/F2_PID_Raw_Si","F2_PID_Raw_Si",100, 46000., 46500.,1000,1., 4096.);
  // F2_PID_Raw_Scint  =  MakeTH2('I', "Sort/F2/F2_PID_Raw_Scint","F2_PID_Raw_Scint",100, 46000., 46500., 1000,1.,4096.);
      
  // F2_PPACT_Trigger  =  MakeTH1('I', "Sort/F2/F2_PPAC_Trigger", "PPAC_Trigger", 4096, 1., 4096.);
   
    char fname[100]; 

    // Yassid 06112013 17:23 Si and CsI histograms
    

  
     
      Double_t pidp[4][2]={{-22350,550},{-22150,550},{-22150,800},{-22350,750}};
      
      PID_Raw_GATE = MakePolyCond("PID_Raw_Gate",4,pidp,"PID_Rf_F2Si");

      // cout<<"OK???????????????????????"<<endl; 
  //  analyser = 2;
  // printf("ENPPAC:   Initializing - %d\n", analyser);




}
//-----------------------------------------------------------
TArtSortProc::~TArtSortProc()
{
   TGo4Log::Info("TArtSortProc: Delete");
   // if (fWinCon) fWinCon->PrintCondition(true);
 
}
//-----------------------------------------------------------
Bool_t TArtSortProc::BuildEvent(TGo4EventElement* dest)
{

  Bool_t isValid=kFALSE; // validity of output event
   int j;
   TArtUnpackEvent* inp_evt  = (TArtUnpackEvent*) GetInputEvent();
   TArtSortEvent* out_evt = (TArtSortEvent*) dest;
   //  cout<<"OK"<<endl; 
   // see comments in UnpackProc
   if((inp_evt==0) || !inp_evt->IsValid()){ // input invalid
      out_evt->SetValid(isValid); // invalid
      return isValid; // must be same is for SetValid
   }
   isValid=kTRUE;

   Int_t cnt(0);
 
   
   /* F2PPAC Sorting Yassid 28022015 */
   
   out_evt-> F2UPPAC_L = inp_evt->v7768_tdc[15][0][0];
   out_evt-> F2UPPAC_D = inp_evt->v7768_tdc[15][1][0];
   out_evt-> F2UPPAC_R = inp_evt->v7768_tdc[15][2][0];
   out_evt-> F2UPPAC_U = inp_evt->v7768_tdc[15][3][0];
   out_evt-> F2UPPAC_A = inp_evt->v7768_tdc[15][4][0];
   out_evt-> F2DPPAC_L = inp_evt->v7768_tdc[15][5][0];
   out_evt-> F2DPPAC_D = inp_evt->v7768_tdc[15][6][0];
   out_evt-> F2DPPAC_R = inp_evt->v7768_tdc[15][7][0];
   out_evt-> F2DPPAC_U = inp_evt->v7768_tdc[15][8][0];
   out_evt-> F2DPPAC_A = inp_evt->v7768_tdc[15][9][0];
    

   
   out_evt-> F3UPPAC_L = inp_evt->v7768_tdc[15][16][0];
   out_evt-> F3UPPAC_D = inp_evt->v7768_tdc[15][17][0];
   out_evt-> F3UPPAC_R = inp_evt->v7768_tdc[15][18][0];
   out_evt-> F3UPPAC_U = inp_evt->v7768_tdc[15][19][0];
   out_evt-> F3UPPAC_A = inp_evt->v7768_tdc[15][20][0];	
   out_evt-> F3DPPAC_L = inp_evt->v7768_tdc[15][21][0];
   out_evt-> F3DPPAC_D = inp_evt->v7768_tdc[15][22][0];
   out_evt-> F3DPPAC_R = inp_evt->v7768_tdc[15][23][0];
   out_evt-> F3DPPAC_U = inp_evt->v7768_tdc[15][24][0]; 
   out_evt-> F3DPPAC_A = inp_evt->v7768_tdc[15][25][0]; 
    
   out_evt-> RFrequ    = inp_evt->v7768_tdc[15][10][0];
  
    
   
   
   
   
    if(out_evt-> F2UPPAC_L>0) F2_u_ppac_l_t->Fill(out_evt-> F2UPPAC_L);
    if(out_evt-> F2UPPAC_D>0) F2_u_ppac_d_t->Fill(out_evt-> F2UPPAC_D);
    if(out_evt-> F2UPPAC_R>0) F2_u_ppac_r_t->Fill(out_evt-> F2UPPAC_R);
    if(out_evt-> F2UPPAC_U>0) F2_u_ppac_u_t->Fill(out_evt-> F2UPPAC_U);
    if(out_evt-> F2UPPAC_A>0) F2_u_ppac_a_t->Fill(out_evt-> F2UPPAC_A); 
    
    if(out_evt-> F2DPPAC_L>0) F2_d_ppac_l_t->Fill(out_evt-> F2DPPAC_L);
    if(out_evt-> F2DPPAC_D>0) F2_d_ppac_d_t->Fill(out_evt-> F2DPPAC_D);
    if(out_evt-> F2DPPAC_R>0) F2_d_ppac_r_t->Fill(out_evt-> F2DPPAC_R);
    if(out_evt-> F2DPPAC_U>0) F2_d_ppac_u_t->Fill(out_evt-> F2DPPAC_U);
    if(out_evt-> F2DPPAC_A>0) F2_d_ppac_a_t->Fill(out_evt-> F2DPPAC_A); 

    
    if(out_evt-> F3UPPAC_L>0) F3_u_ppac_l_t->Fill(out_evt-> F3UPPAC_L);
    if(out_evt-> F3UPPAC_D>0) F3_u_ppac_d_t->Fill(out_evt-> F3UPPAC_D);
    if(out_evt-> F3UPPAC_R>0) F3_u_ppac_r_t->Fill(out_evt-> F3UPPAC_R);
    if(out_evt-> F3UPPAC_U>0) F3_u_ppac_u_t->Fill(out_evt-> F3UPPAC_U);
    if(out_evt-> F3UPPAC_A>0) F3_u_ppac_a_t->Fill(out_evt-> F3UPPAC_A); 

    if(out_evt-> F3DPPAC_L>0) F3_d_ppac_l_t->Fill(out_evt-> F3DPPAC_L);
    if(out_evt-> F3DPPAC_D>0) F3_d_ppac_d_t->Fill(out_evt-> F3DPPAC_D);
    if(out_evt-> F3DPPAC_R>0) F3_d_ppac_r_t->Fill(out_evt-> F3DPPAC_R);
    if(out_evt-> F3DPPAC_U>0) F3_d_ppac_u_t->Fill(out_evt-> F3DPPAC_U);
    if(out_evt-> F3DPPAC_A>0) F3_d_ppac_a_t->Fill(out_evt-> F3DPPAC_A); 
    // ---------------------------    


   int f2ppac[10],f3ppac[10];
   double  F2_aX_mrad,F2_aY_mrad;
   double  F3_aX_mrad,F3_aY_mrad;
   double F2ExtrapolationX_f2viewer,F2ExtrapolationY_f2viewer;
   double F3ExtrapolationX_target,F3ExtrapolationY_target;
   double dz;


   for (int i=0;i<10;i++){
	f2ppac[i] = inp_evt->v7768_tdc[15][i][0];
        f3ppac[i] = inp_evt->v7768_tdc[15][16+i][0];	
//       printf("EN_PPAC_Cal::ENcode: %d   %d   %d\n",i,f2ppac[i],raw[2][1][i]);
    }



 SetPosition(1,0, f2ppac);
    SetPosition(3,0, f3ppac);

    F2_aX_mrad = GetF2_aX_mrad();
    F2_aY_mrad  = GetF2_aY_mrad();
    F3_aX_mrad = GetF3_aX_mrad();
    F3_aY_mrad = GetF3_aY_mrad();

    //F2 viewer
    F2ExtrapolationX_f2viewer = GetF2ExtrapolationX(775);
    F2ExtrapolationY_f2viewer = GetF2ExtrapolationY(775);

    //F3 target 
    F3ExtrapolationX_target = GetF3ExtrapolationX(1633); // For E435,E436,E437,E448
   F3ExtrapolationY_target  = GetF3ExtrapolationY(1633); // For E435,E436,E437,E448




 

   /////////fill////////////
   if(tcal[1][0]>-2000&&tcal[1][0]<2000) F2_u_ppac_l_tns->Fill(tcal[1][0]);
   if(tcal[1][1]>-2000&&tcal[1][1]<2000) F2_u_ppac_d_tns->Fill(tcal[1][1]);
   if(tcal[1][2]>-2000&&tcal[1][2]<2000) F2_u_ppac_r_tns->Fill(tcal[1][2]);
   if(tcal[1][3]>-2000&&tcal[1][3]<2000) F2_u_ppac_u_tns->Fill(tcal[1][3]);
   if(tcal[1][4]>-2000&&tcal[1][4]<2000) F2_u_ppac_a_tns->Fill(tcal[1][4]);

   if(tcal[2][0]>-2000&&tcal[2][0]<2000) F2_d_ppac_l_tns->Fill(tcal[2][0]);
   if(tcal[2][1]>-2000&&tcal[2][1]<2000) F2_d_ppac_d_tns->Fill(tcal[2][1]);
   if(tcal[2][2]>-2000&&tcal[2][2]<2000) F2_d_ppac_r_tns->Fill(tcal[2][2]);
   if(tcal[2][3]>-2000&&tcal[2][3]<2000) F2_d_ppac_u_tns->Fill(tcal[2][3]);
   if(tcal[2][4]>-2000&&tcal[2][4]<2000) F2_d_ppac_a_tns->Fill(tcal[2][4]);


   if(tcal[3][0]>-2000&&tcal[3][0]<2000) F3_u_ppac_l_tns->Fill(tcal[3][0]);
   if(tcal[3][1]>-2000&&tcal[3][1]<2000) F3_u_ppac_d_tns->Fill(tcal[3][1]);
   if(tcal[3][2]>-2000&&tcal[3][2]<2000) F3_u_ppac_r_tns->Fill(tcal[3][2]);
   if(tcal[3][3]>-2000&&tcal[3][3]<2000) F3_u_ppac_u_tns->Fill(tcal[3][3]);
   if(tcal[3][4]>-2000&&tcal[3][4]<2000) F3_u_ppac_a_tns->Fill(tcal[3][4]);

   if(tcal[4][0]>-2000&&tcal[4][0]<2000) F3_d_ppac_l_tns->Fill(tcal[4][0]);
   if(tcal[4][1]>-2000&&tcal[4][1]<2000) F3_d_ppac_d_tns->Fill(tcal[4][1]);
   if(tcal[4][2]>-2000&&tcal[4][2]<2000) F3_d_ppac_r_tns->Fill(tcal[4][2]);
   if(tcal[4][3]>-2000&&tcal[4][3]<2000) F3_d_ppac_u_tns->Fill(tcal[4][3]);
   if(tcal[4][4]>-2000&&tcal[4][4]<2000) F3_d_ppac_a_tns->Fill(tcal[4][4]);

   if(posXmm[1]>-60&&posXmm[1]<60) F2_u_ppac_Xmm->Fill(posXmm[1]);
   if(posYmm[1]>-60&&posYmm[1]<60) F2_u_ppac_Ymm->Fill(posYmm[1]);
   if(posXmm[2]>-60&&posXmm[2]<60) F2_d_ppac_Xmm->Fill(posXmm[2]);
   if(posYmm[2]>-60&&posYmm[2]<60) F2_d_ppac_Ymm->Fill(posYmm[2]);

   if(posXmm[3]>-60&&posXmm[3]<60) F3_u_ppac_Xmm->Fill(posXmm[3]);
   if(posYmm[3]>-60&&posYmm[3]<60) F3_u_ppac_Ymm->Fill(posYmm[3]);
   if(posXmm[4]>-60&&posXmm[4]<60) F3_d_ppac_Xmm->Fill(posXmm[4]);
   if(posYmm[4]>-60&&posYmm[4]<60) F3_d_ppac_Ymm->Fill(posYmm[4]);

   if(F2_aX_mrad>-60&&F2_aX_mrad<60) F2_ppac_aXmrad->Fill(F2_aX_mrad);
  if(F2_aY_mrad>-60&&F2_aY_mrad<60) F2_ppac_aYmrad->Fill(F2_aY_mrad);
   if(F2_aX_mrad>-60&&F2_aX_mrad<60) F2_ppac_aXmrad->Fill(F2_aX_mrad);
  if(F2_aY_mrad>-60&&F2_aY_mrad<60) F2_ppac_aYmrad->Fill(F2_aY_mrad);


  ///////D2/////////////
  if(posXmm[1]>-60&&posXmm[1]<60&&posYmm[1]>-60&&posYmm[1]<60) F2_u_ppac_XYmm->Fill(posXmm[1],posYmm[1]);
  if(posXmm[2]>-60&&posXmm[2]<60&&posYmm[2]>-60&&posYmm[2]<60) F2_d_ppac_XYmm->Fill(posXmm[2],posYmm[2]);
  if(F2ExtrapolationX_f2viewer>-60&&F2ExtrapolationX_f2viewer<60&&F2ExtrapolationY_f2viewer>-60&&F2ExtrapolationY_f2viewer<60) F2_Viewer_XYmm->Fill(F2ExtrapolationX_f2viewer,F2ExtrapolationY_f2viewer);
  if(posXmm[1]>-60&&posXmm[1]<60&&F2_aX_mrad>-60&&F2_aX_mrad<60) F2_X_vs_aX->Fill(posXmm[1],F2_aX_mrad);
  if(posYmm[1]>-60&&posYmm[1]<60&&F2_aY_mrad>-60&&F2_aY_mrad<60) F2_Y_vs_aY->Fill(posYmm[1],F2_aY_mrad);


  if(posXmm[3]>-60&&posXmm[3]<60&&posYmm[3]>-60&&posYmm[3]<60) F3_u_ppac_XYmm->Fill(posXmm[3],posYmm[3]);
  if(posXmm[4]>-60&&posXmm[4]<60&&posYmm[4]>-60&&posYmm[4]<60) F3_d_ppac_XYmm->Fill(posXmm[4],posYmm[4]);
  if(F3ExtrapolationX_target>-60&&F3ExtrapolationX_target<60&&F3ExtrapolationY_target>-60&&F3ExtrapolationY_target<60) F3_target_XYmm->Fill(F3ExtrapolationX_target,F3ExtrapolationY_target);

 if(posXmm[3]>-60&&posXmm[3]<60&&F3_aX_mrad>-60&&F3_aX_mrad<60) F3_X_vs_aX->Fill(posXmm[3],F3_aX_mrad);
  if(posYmm[3]>-60&&posYmm[3]<60&&F3_aY_mrad>-60&&F3_aY_mrad<60) F3_Y_vs_aY->Fill(posYmm[3],F3_aY_mrad);

  for(j=0; j<1000;j++){
        dz= -500 + 2500.0*rand()/RAND_MAX;
         
	if(GetF2ExtrapolationX(dz)>-60&&GetF2ExtrapolationX(dz)<60&&dz>-500&&dz<1500.)F2ExtrapolationZmm_Xmm->Fill(dz,GetF2ExtrapolationX(dz));
	if(GetF2ExtrapolationY(dz)>-60&&GetF2ExtrapolationY(dz)<60&&dz>-500&&dz<1500.) F2ExtrapolationZmm_Ymm->Fill(dz,GetF2ExtrapolationY(dz));

	if(GetF3ExtrapolationX(dz)>-60&&GetF3ExtrapolationX(dz)<60&&dz>-500.&&dz<2000.) F3ExtrapolationZmm_Xmm->Fill(dz,GetF3ExtrapolationX(dz));
	if(GetF3ExtrapolationY(dz)>-60&&GetF3ExtrapolationY(dz)<60&&dz>-500.&&dz<2000.) F3ExtrapolationZmm_Ymm->Fill(dz,GetF3ExtrapolationY(dz));



   }

    // if(out_evt-> F2UPPAC_L>0) F2_u_ppac_l_tcal->Fill(out_evt-> F2UPPAC_L);
   
    if(out_evt-> RFrequ>0)
      Rf->Fill(out_evt-> RFrequ);
    
   

    if(out_evt-> F2DPPAC_L>0 && out_evt-> F2DPPAC_R>0) 
      F2_d_ppac_pos_X->Fill(out_evt-> F2DPPAC_L - out_evt-> F2DPPAC_R);
    if(out_evt-> F2UPPAC_L>0 && out_evt-> F2UPPAC_R>0)
      F2_u_ppac_pos_X->Fill(out_evt-> F2UPPAC_L - out_evt-> F2UPPAC_R);
    
    if(out_evt-> F2DPPAC_D>0 && out_evt-> F2DPPAC_U>0) 
      F2_d_ppac_pos_Y->Fill(out_evt-> F2DPPAC_D - out_evt-> F2DPPAC_U);
    if(out_evt-> F2UPPAC_D>0 && out_evt-> F2UPPAC_U>0)
      F2_u_ppac_pos_Y->Fill(out_evt-> F2UPPAC_D - out_evt-> F2UPPAC_U);
    
    if(out_evt-> F3UPPAC_L>0 && out_evt-> F3UPPAC_R>0) 
      F3_u_ppac_pos_X->Fill(out_evt-> F3UPPAC_L - out_evt-> F3UPPAC_R);
    if(out_evt-> F3UPPAC_D>0 && out_evt-> F3UPPAC_U>0) 
      F3_u_ppac_pos_Y->Fill(out_evt-> F3UPPAC_D - out_evt-> F3UPPAC_U);  
    
    
    if(out_evt-> F3UPPAC_L>0 && out_evt-> F3UPPAC_R>0)	      
      F3_d_ppac_pos_X->Fill(out_evt-> F3UPPAC_L - out_evt-> F3UPPAC_R);
   
   
    if(out_evt-> F3UPPAC_D>0 && out_evt-> F3UPPAC_U>0)
      F3_d_ppac_pos_Y->Fill(out_evt-> F3UPPAC_D - out_evt-> F3UPPAC_U);  
  
    
   

    if(out_evt->F2UPPAC_L>0 && out_evt->F2UPPAC_R>0 && out_evt-> F2UPPAC_U>0 &&  out_evt-> F2UPPAC_D>0)
      F2_u_ppac_pos->Fill(  out_evt-> F2UPPAC_L - out_evt-> F2UPPAC_R ,out_evt-> F2UPPAC_D - out_evt-> F2UPPAC_U      );
    
    if(out_evt->F2DPPAC_L>0 && out_evt->F2DPPAC_R>0 && out_evt-> F2DPPAC_U>0 &&  out_evt-> F2DPPAC_D>0)
      F2_d_ppac_pos->Fill(  out_evt-> F2DPPAC_L - out_evt-> F2DPPAC_R ,out_evt-> F2DPPAC_D - out_evt-> F2DPPAC_U      );
    
    if(out_evt->F3UPPAC_L>0 && out_evt->F3UPPAC_R>0 && out_evt-> F3UPPAC_U>0 &&  out_evt-> F3UPPAC_D>0) 
      F3_u_ppac_pos->Fill(  out_evt-> F3UPPAC_L - out_evt-> F3UPPAC_R ,out_evt-> F3UPPAC_D - out_evt-> F3UPPAC_U      );
    
    
    
    if(out_evt->F3DPPAC_L>0 && out_evt->F3DPPAC_R>0 && out_evt-> F3DPPAC_U>0 &&  out_evt-> F3DPPAC_D>0)
      F3_d_ppac_pos->Fill(out_evt-> F3DPPAC_L - out_evt-> F3DPPAC_R ,out_evt-> F3DPPAC_D - out_evt-> F3DPPAC_U      );
    // -------------------------
    
   /*  if(PID_Raw_GATE->Test(out_evt-> RFrequ-out_evt->F2_Tref,out_evt-> F2SSD)){
      if(out_evt->F2UPPAC_L>0 && out_evt->F2UPPAC_R>0 && out_evt-> F2UPPAC_U>0 &&  out_evt-> F2UPPAC_D>0)F2_u_ppac_pos_cond->Fill(out_evt-> F2UPPAC_L - 	out_evt-> F2UPPAC_R ,out_evt-> F2UPPAC_D - out_evt-> F2UPPAC_U      )    ;
     
    if(out_evt->F2DPPAC_L>0 && out_evt->F2DPPAC_R>0 && out_evt-> F2DPPAC_U>0 &&  out_evt-> F2DPPAC_D>0) F2_d_ppac_pos_cond->Fill(  out_evt-> F2DPPAC_L - 	out_evt-> F2DPPAC_R ,out_evt-> F2DPPAC_D - out_evt-> F2DPPAC_U      )    ;
     
     if(out_evt->F3UPPAC_L>0 && out_evt->F3UPPAC_R>0 && out_evt-> F3UPPAC_U>0 &&  out_evt-> F3UPPAC_D>0) F3_u_ppac_pos_cond->Fill(  out_evt-> F3UPPAC_L - 	out_evt-> F3UPPAC_R ,out_evt-> F3UPPAC_D - out_evt-> F3UPPAC_U      );     ;
     
    if(out_evt->F3DPPAC_L>0 && out_evt->F3DPPAC_R>0 && out_evt-> F3DPPAC_U>0 &&  out_evt-> F3DPPAC_D>0) F3_d_ppac_pos_cond->Fill(out_evt-> F3DPPAC_L - 		out_evt-> F3DPPAC_R ,out_evt-> F3DPPAC_D - out_evt-> F3DPPAC_U      );
	}*/

	    	    
	    // see comments in UnpackProc Yassid
	    out_evt->SetValid(isValid);
	    return isValid;
}

TH1* TArtSortProc::MakeH1I_Hodo(const char*	foldername, 
                                 int		layer,int position,int var, int index,
                                 const char* xtitle) {
   char						layername[100];
   if(layer==0) sprintf(layername,"DE");	//  layername="DE";
     else					if(layer==1) sprintf(layername,"EONE");
    else					if(layer==2) sprintf(layername,"ETWO"); ;

   char positionname[100];
    if(position==0 )sprintf(positionname,"up"); 
    else	if(position==1) sprintf(positionname,"down");
    else	if(position==2) sprintf(positionname,"left"); 
    else	if(position==3) sprintf(positionname,"right");
    else	if(position==4) sprintf(positionname,"Position");
    else	if(position==5) sprintf(positionname,"Energy");   
 
   char varname[100];
   if(var==0) sprintf(varname,"t"); 
   else if(var==1)  sprintf(varname,"q"); 		     
   else if(var==2)  sprintf(varname,"pos");
   else if(var==3)  sprintf(varname,"E");
   

    char	fullname[100];
    char	histoname[100];
    sprintf(fullname,"%s_%s/%s/%s_%s_%s_%02d",foldername,layername,varname,layername,positionname,varname,index);
    sprintf(histoname,"%s_%s_%s_%02d",layername,positionname,varname,index);
 
    if( (position==0) | (position==1) | (position==2) | (position==3))  return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
    else	if(position==4) return MakeTH1('I',fullname,histoname, 4096., 2000., 2000.);
    else	if(position==5) return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
}

TH1* TArtSortProc::MakeH1I_DSSD(const char*	foldername, 
				int		position,int layer,int strip,
                                 const char* xtitle) {
   char						layername[100];
   if(layer==1) sprintf(layername,"bias");
   else						if(layer==2) sprintf(layername,"ground");

   // char positionname[100];
   
 
   // char varname[100];
 
    

    char	fullname[100];
    char	histoname[100];
    sprintf(fullname,"%s_%02d/%02d_%s_%02d",foldername,position,position,layername,strip);
    sprintf(histoname,"DSSD_%02d_%s_%02d",position,layername,strip);
 
    return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
   
}


TH1* TArtSortProc::MakeH1I_CSI(const char*	foldername, 
				int		csiarray,int csinumber) {
   
    char	fullname[100];
    char	histoname[100];
    sprintf(fullname,"%s_%02d/%02d_%02d",foldername,csiarray,csiarray,csinumber);
    sprintf(histoname,"CsI_%02d_%02d",csiarray,csinumber);
 
    return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
   
}


TH1* TArtSortProc::MakeH1I_SSD(const char*	foldername, 
				int ssdnumber) {
   
    char	fullname[100];
    char	histoname[100];
    sprintf(fullname,"%s_%02d",foldername,ssdnumber);
    sprintf(histoname,"SSD_%02d",ssdnumber);
 
    return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
   
}

TH1* TArtSortProc::MakeH1I_TPCSi(const char*	foldername, 
			   int			side,int position){
   
    char	fullname[100];
    char	histoname[100];
    char	sidename[100];
    char	positionname[100];

    if(side==0) sprintf(sidename,"Center");
    else	if(side==1) sprintf(sidename,"Right");
    else	if(side==2) sprintf(sidename,"Left");

    if(position==0) sprintf(positionname,"Up");
    else	if(position==1) sprintf(positionname,"Down");
    else	if(position==2) sprintf(positionname,"Right-Up");
    else	if(position==3) sprintf(positionname,"Right-Down");
    else	if(position==4) sprintf(positionname,"Left-Up");
    else	if(position==5) sprintf(positionname,"Left-Down");
   
    
    

    sprintf(fullname,"%s/TPCSi_%s/TPCSi_%s_%s",foldername,sidename,sidename,positionname);
    sprintf(histoname,"TPCSi_%s_%s",sidename,positionname);
 
    return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
   
}

TH1* TArtSortProc::MakeH1I_TPCCsI(const char*	foldername, 
				  int		position,int number,int side){
   
    char	fullname[100];
    char	histoname[100];
     char	sidename[100];
    char	positionname[100];

    
     if(side==0) sprintf(sidename,"Center");

     if(position==0) sprintf(positionname,"Right-Up");
    else	if(position==1) sprintf(positionname,"Right-Down");
    else	if(position==2) sprintf(positionname,"Left-Up");
    else	if(position==3) sprintf(positionname,"Left-Down");

     sprintf(fullname,"%s/TPCCSI_%s/TPCCSI_%s_%02d",foldername,sidename,positionname,number);
     sprintf(histoname,"TPCCsI_%s_%s_%02d",sidename,positionname,number);
 
 
    return MakeTH1('I',fullname,histoname, 4096., 1., 4096.);
   
}

int TArtSortProc::ReadParameters(char* filename){
   fi.open(filename,ios::in);

  if (fi.is_open()){
    //   cout<<filename<<endl;
    double valread[5];
    int ch2nsflag;
    char* buff;
    //read ch2ns 
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,5) == -1) goto l20;
         for (int j=0;j<5;j++) ch2ns[i][j]=valread[j];
       }else for (int j=0;j<5;j++) ch2ns[i][j]=1.;
     }
    //read qdc
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,5) == -1) goto l20;
         for (int j=0;j<5;j++) ch2qdc[i][j]=valread[j];
       }else for (int j=0;j<5;j++) ch2qdc[i][j]=1.;
     }
     //read qdc ped
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,5) == -1) goto l20;
         for (int j=0;j<5;j++) qdcped[i][j]=valread[j];
       }else for (int j=0;j<5;j++) qdcped[i][j]=0;
     }

   //  ns2mm
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,2) == -1) goto l20;
         for (int j=0;j<2;j++) ns2mm[i][j]=valread[j];
       }else for (int j=0;j<2;j++) ns2mm[i][j]=1.;
     }
     //  in off set
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,2) == -1) goto l20;
         for (int j=0;j<2;j++) in_offset[i][j]=valread[j];
       }else for (int j=0;j<2;j++) in_offset[i][j]=0.;
     }
    //  out off set
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,2) == -1) goto l20;
         for (int j=0;j<2;j++) out_offset[i][j]=valread[j];
 
       }else for (int j=0;j<2;j++) out_offset[i][j]=0.;
     }
      //  geometry off set
    buff = GetNextLine('c');if (buff ==NULL) goto l20;
    ch2nsflag = atoi(buff);
    for (int i=0;i<5;i++){
       buff = GetNextLine('c');if (buff ==NULL) goto l20;
       if (ch2nsflag==1){
         if (Put2Array(buff,valread,2) == -1) goto l20;
         for (int j=0;j<2;j++) geo_offset[i][j]=valread[j];
       }else for (int j=0;j<2;j++) geo_offset[i][j]=0.;
     }
     for (int i=0;i<5;i++){
       for (int j=0;j<2;j++) offset[i][j]= in_offset[i][j]+out_offset[i][j]+geo_offset[i][j];
       //   for (int j=0;j<2;j++)  cout<<in_offset[i][j]<<" "<<out_offset[i][j]<<" "<<geo_offset[i][j]<< endl;
     }

     fi.close();
     printf("EN_PPAC_Cal: Parameters file :\"%s\" |--> LOADED!!!.\n",filename); 
     return 0;
  }else{
     printf("EN_PPAC_Cal: Parameters file :\"%s\" cannot open |--> NOT load!!!\n",filename);
     goto def;
  }
l20:  printf("EN_PPAC_Cal: Parameters file :\"%s\" not true format |--> NOT load!!!\n",filename);
def:;
  for (int i=0;i<5;i++){
     for (int j=0;j<5;j++){
        ch2ns[i][j]= 1;
        ch2qdc[i][j] =1;
        qdcped[i][j] =0;
     }
  }
  for (int i=0;i<5;i++){
     for (int j=0;j<2;j++){
        ns2mm[i][j] = 1;
   	in_offset[i][j] = 0;
   	out_offset[i][j] = 0;
   	geo_offset[i][j] = 0;
        offset[i][j]= in_offset[i][j]+out_offset[i][j]+geo_offset[i][j];
     }
  }
  return -1;
}

// ***********************************************************************
char* TArtSortProc::ltrim (char s[])
{
    while (*s == 32) s++;
    return s;
}
// *********************************************************************** 
char* TArtSortProc::rtrim (char s[])
{
    int i = 0;
    while (s[i]) i++ ;
    while (s[i-1]==32) i--;
    s[i] = 0 ;
    return s;  
}
// ***********************************************************************
char * TArtSortProc::trim (char s[])
{
    return ltrim(rtrim(s));  
}
// ***********************************************************************
int TArtSortProc::Put2Array(char*s,double* val,int nval){
  int nf =0;
  s = trim(s);
  char * pch;
  pch = strtok (s," 	");
  while (pch != NULL && nf<nval)
  {
    val[nf] = atof(pch);
    pch = strtok (NULL, " 	");
    nf++;
  }
  if (pch != NULL) strcpy(s,pch);
  if (nf<nval) return -1;
  return 0;
}
// ***********************************************************************
int TArtSortProc::Put2Array(char* s,int* val,int nval){
  int nf =0;
  s = trim(s);
  char * pch;
  pch = strtok (s," 	");
  while (pch != NULL && nf<nval)
  {
    val[nf] = atoi(pch);
    pch = strtok (NULL, " 	");
    nf++;
  }
  if (pch != NULL) strcpy(s,pch);
  if (nf<nval) return -1;
  return 0;
}
// ***********************************************************************
char* TArtSortProc::GetNextLine(char s){
   char buffer[1000];
   char* buff; 
//   ifstream fi;
    while (1)
    {
        if (fi.eof()) return NULL;
        buffer[0] = '\0';
        fi.getline(buffer, 1000, '\n');
        buff=trim(buffer);
        if (strlen(buff) > 0)
        {
            if (buff[0] != s)
            {
                return buff;
            }
        }
    }
    return NULL; 
}
// ***********************************************************************
// ***********************************************************************
void   TArtSortProc::SetPosition(int ppacNo, int Left,int Right,int Down,int Up, int Anode ){
  if (flagprm<0) printf("EN_PPAC:     Khong doc dc prm file\n");
  traw[ppacNo][0]=Left;
  traw[ppacNo][1]=Down;
  traw[ppacNo][2]=Right;
  traw[ppacNo][3]=Up;
  if (Anode>0) traw[ppacNo][4]=Anode;
//  printf(" No L D R U:  %d    %d    %d     %d    %d \n",ppacNo, Left,Down,Right,Up);
  for (int i=0;i<5;i++) tcal[ppacNo][i]=traw[ppacNo][i]*ch2ns[ppacNo][i];
  if (traw[ppacNo][0]>0 && traw[ppacNo][2]>0) {
       posXns[ppacNo] = tcal[ppacNo][0] - tcal[ppacNo][2];
       posXmm[ppacNo] = posXns[ppacNo]*ns2mm[ppacNo][0] -offset[ppacNo][0];
       //      cout<<ppacNo<<"  "<<posXns[ppacNo]*ns2mm[ppacNo][0]<<" --> "<<posXmm[ppacNo]<<endl;
  }else{ 
       posXns[ppacNo]=-1000;
       posXmm[ppacNo]=-1000;
  }  
  if (traw[ppacNo][1]>0 && traw[ppacNo][3]>0) {
       posYns[ppacNo] = tcal[ppacNo][1] - tcal[ppacNo][3];
       posYmm[ppacNo] = posYns[ppacNo]*ns2mm[ppacNo][1] -offset[ppacNo][1];
     
  }else{ 
       posYns[ppacNo]=-1000;
       posYmm[ppacNo]=-1000;
  }

}
// ***********************************************************************
void   TArtSortProc::SetPosition(int ppacNo, int start, int* rawin){
  SetPosition(ppacNo,  rawin[start+0],rawin[start+2],rawin[start+1],rawin[start+3],rawin[start+4]  );
  SetPosition(ppacNo+1,rawin[start+5],rawin[start+7],rawin[start+6],rawin[start+8],rawin[start+9]  );
}
// ***********************************************************************
void   TArtSortProc::SetPosition(int start1, int* rawin1, int start2, int* rawin2){
   SetPosition(1, start1, rawin1);
   SetPosition(3, start2, rawin2);
}
// ***********************************************************************
double TArtSortProc::GetF2_aX_mrad(){
   double exX;
   if (abs(posXmm[1])<50 && abs(posXmm[2])<50)
      exX =  atan2(posXmm[2] - posXmm[1],F2distance);
   else exX = -10;
   return exX*1000;
}
// ***********************************************************************
double TArtSortProc::GetF2_aY_mrad(){
   double exX;
   if (abs(posYmm[1])<50 && abs(posYmm[2])<50)
      exX =  atan2(posYmm[2] - posYmm[1],F2distance);
   else exX = -10;
   return exX*1000;
}
// ***********************************************************************
double TArtSortProc::GetF3_aX_mrad(){
  double exX;
   if (abs(posXmm[3])<50 && abs(posXmm[4])<50)
      exX =  atan2(posXmm[4] - posXmm[3],F3distance);
   else exX = -10;
   return exX*1000;
}
// ***********************************************************************
double TArtSortProc::GetF3_aY_mrad(){
   double exX;
   if (abs(posYmm[3])<50 && abs(posYmm[4])<50)
      exX =  atan2(posYmm[4] - posYmm[3],F3distance);
   else exX = -10;
   return exX*1000;
}
// ***********************************************************************
double TArtSortProc::GetF2ExtrapolationX(double atZ){
   double exX;
   if (abs(posXmm[1])<50 && abs(posXmm[2])<50)
      exX =  posXmm[1] + (posXmm[2] - posXmm[1])*atZ/F2distance;
   else exX = -1000;
   return exX;
}
// ***********************************************************************
double TArtSortProc::GetF2ExtrapolationY(double atZ){
  double exX;
   if (abs(posYmm[1])<50 && abs(posYmm[2])<50)
      exX =  posYmm[1] + (posYmm[2] - posYmm[1])*atZ/F2distance;
   else exX = -1000;
   return exX;
}
// ***********************************************************************
double TArtSortProc::GetF3ExtrapolationX(double atZ){
  double exX;
   if (abs(posXmm[3])<50 && abs(posXmm[4])<50)
      exX =  posXmm[3] + (posXmm[4] - posXmm[3])*atZ/F3distance;
   else exX = -1000;
   return exX;
}
// ***********************************************************************
double TArtSortProc::GetF3ExtrapolationY(double atZ){
   double exX;
   if (abs(posYmm[3])<50 && abs(posYmm[4])<50)
      exX =  posYmm[3] + (posYmm[4] - posYmm[3])*atZ/F3distance;
   else exX = -1000;
   return exX;
}
