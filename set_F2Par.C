void set_F2Par()
{
   TArtF2Param *fp = (TArtF2Param*) go4->GetParameter("F2Param","TArtF2Param");
   if(fp==0) return;

   // set values here-----------
   fp->frP1    = 200;
   fp->frP2    = 200;
   fp->fbHisto = kTRUE;

   fp->fArr.Set(4);
   fp->fArr[0] = 34;
   fp->fArr[1] = 2345;
   fp->fArr[2] = 3456;
   fp->fArr[3] = 4567;
   
   fp->fF2UPPAC_tdc_param[0]= 0.1; // F2 U Left
   fp->fF2UPPAC_tdc_param[1]= 0.1; // F2 U Right
   fp->fF2UPPAC_tdc_param[2]= 0.1; //  F2 U Up
   fp->fF2UPPAC_tdc_param[3]= 0.1; // F2 U Down
   // fp->fF2UPPAC_tdc_param[4]= 0.036178; //F2 U Anode

   fp->fF2DPPAC_tdc_param[0]= 0.1;// F2 D Left
   fp->fF2DPPAC_tdc_param[1]= 0.1; // F2 D Right
   fp->fF2DPPAC_tdc_param[2]= 0.1; // F2 D Up
   fp->fF2DPPAC_tdc_param[3]= 0.1; // F2 D Down
   //fp->fF2DPPAC_tdc_param[4]= 0.035814; //F2 D Anode*/
      
   fp->fF2UPPAC_tdc_ns2mm[0]=0.63419;// f2 Upstream X slope
   fp->fF2UPPAC_tdc_ns2mm[1]=0.62479;//f2 Upstream Y slope
   fp->fF2UPPAC_tdc_ns2mm[2]=0.0;//f2 Upstream X offset
   fp->fF2UPPAC_tdc_ns2mm[3]=0.0;//f2 Upstream Y offset

   fp->fF2DPPAC_tdc_ns2mm[0]=0.62691;//f2 Downstream X slope
   fp->fF2DPPAC_tdc_ns2mm[1]=0.62147;//f2 Downstream Y slope
   fp->fF2DPPAC_tdc_ns2mm[2]=0.0;//f2 Downstream X offset
   fp->fF2DPPAC_tdc_ns2mm[3]=0.0;//f2 Downstream Y offset

   //   TETSUYA CHANGE 20140529
   //   fp->fF2UPPAC_e390_offset[0]= -1.7438+3.93 - 1.64; //f2U X
   //   fp->fF2UPPAC_e390_offset[1]= 0.5954;//f2U Y
   
   //   fp->fF2DPPAC_e390_offset[0]= -1.3177 + 4.635 -3.68; //f2D X
   //   fp->fF2DPPAC_e390_offset[1]= -0.38158;//f2D Y
   
   fp->zpos[0]= 0; // F2 Upstream PPAC
   fp->zpos[1]= 482; // F2 Downstream PPAC
   fp->zpos[2]= 88; // F2 Plastic Scintillator 
   fp->zpos[3]= 630;  //F2 Gate valve
   fp->zpos[4]= 755;  // F2 Viewer
   fp->zpos[5]= 1059; // F2 Entrance of Scattering chamber
   fp->zpos[6]= 1619; // F2 Target position
   fp->zpos[7]= 2179; //  F2 Scattering chamber exit
   fp->zpos[8]= 5459; // Hodoscope

   /* fp-> fF2UPPAC_X_slope= 1.255; // mm/ns
   fp-> fF2UPPAC_Y_slope= 1.263;
   fp-> fF2DPPAC_X_slope= 1.238;
   fp-> fF2DPPAC_Y_slope= 1.237;
       
   fp-> fF2UPPAC_X_offset= 0.0;
   fp-> fF2UPPAC_Y_offset= 0.0;
   fp-> fF2DPPAC_X_offset= 1.18;
   fp-> fF2DPPAC_Y_offset= - 2.1;*/
}
