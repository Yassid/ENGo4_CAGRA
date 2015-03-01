void set_F3Par()
{
   TArtF3Param *fp = (TArtF3Param*) go4->GetParameter("F3Param","TArtF3Param");
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
      
   fp->fF3UPPAC_tdc_param[0]= 0.1; // F3 U Left
   fp->fF3UPPAC_tdc_param[1]= 0.1; // F3 U Right
   fp->fF3UPPAC_tdc_param[2]= 0.1; //  F3 U Up
   fp->fF3UPPAC_tdc_param[3]= 0.1; // F3 U Down
   // fp->fF3UPPAC_tdc_param[4]= 0.036178; //F3 U Anode
   
   fp->fF3DPPAC_tdc_param[0]= 0.1;// F3 D Left
   fp->fF3DPPAC_tdc_param[1]= 0.1; // F3 D Right
   fp->fF3DPPAC_tdc_param[2]= 0.1; // F3 D Up
   fp->fF3DPPAC_tdc_param[3]= 0.1; // F3 D Down
   //fp->fF3DPPAC_tdc_param[4]= 0.035814; //F3 D Anode*/
   
   fp->fF3UPPAC_tdc_ns2mm[0]=1.226/2.0;// f2 Upstream X slope //Yassid F3 PPAC Parameters for E407 Values taken from wiki divided by 2
   fp->fF3UPPAC_tdc_ns2mm[1]=1.221/2.0;//f2 Upstream Y slope
   fp->fF3UPPAC_tdc_ns2mm[2]=0.85;//f2 Upstream X offset
   fp->fF3UPPAC_tdc_ns2mm[3]=0.90;//f2 Upstream Y offset

   fp->fF3DPPAC_tdc_ns2mm[0]=1.234/2.0;//f2 Downstream X slope
   fp->fF3DPPAC_tdc_ns2mm[1]=1.235/2.0;//f2 Downstream Y slope
   fp->fF3DPPAC_tdc_ns2mm[2]=0.26;//f2 Downstream X offset
   fp->fF3DPPAC_tdc_ns2mm[3]=0.29;//f2 Downstream Y offset
   
   //   TETSUYA CHANGE 20140529

   // fp->fF3UPPAC_e390_offset[0]= -1.7438+3.93 - 1.64; //f2U X
   // fp->fF3UPPAC_e390_offset[1]= 0.5954;//f2U Y
   // fp->fF3DPPAC_e390_offset[0]= -1.3177 + 4.635 -3.68; //f2D X
   // fp->fF3DPPAC_e390_offset[1]= -0.38158;//f2D Y
   
   fp->zpos[0]= 0; // F3 Upstream PPAC
   fp->zpos[1]= 482; // F3 Downstream PPAC
   fp->zpos[2]= 88; // F3 Plastic Scintillator 
   fp->zpos[3]= 630;  //F3 Gate valve
   fp->zpos[4]= 755;  // F3 Viewer
   fp->zpos[5]= 1059; // F3 Entrance of Scattering chamber
   fp->zpos[6]= 1619; // F3 Target position
   fp->zpos[7]= 2179; //  F3 Scattering chamber exit
   fp->zpos[8]= 5459; // Hodoscope

   /* 
      fp-> fF3UPPAC_X_slope= 1.255; // mm/ns
      fp-> fF3UPPAC_Y_slope= 1.263;
      fp-> fF3DPPAC_X_slope= 1.238;
      fp-> fF3DPPAC_Y_slope= 1.237;
      
      fp-> fF3UPPAC_X_offset= 0.0;
      fp-> fF3UPPAC_Y_offset= 0.0;
      fp-> fF3DPPAC_X_offset= 1.18;
      fp-> fF3DPPAC_Y_offset= -2.1;
   */
}
