#include "TArtProc.h"
#include "Riostream.h"
#include "TH1.h"
#include "TH2.h"
#include "TCutG.h"
#include "snprintf.h"
#include "TGo4WinCond.h"
#include "TGo4PolyCond.h"
#include "TGo4CondArray.h"
#include "TGo4Picture.h"
//#include "TArtParam.h"
// if we have this class:
#include "TArtRawEvent.h"
#include "TArtUnpackEvent.h"
#include "segidlist.h"

//***********************************************************
TArtProc::TArtProc() : TGo4EventProcessor("Proc")
{
  cout << "**** TArtProc: Create instance " << endl;
}
//***********************************************************
TArtProc::~TArtProc()
{
  cout << "**** TArtProc: Delete instance " << endl;
}
//***********************************************************
// this one is used in standard factory
TArtProc::TArtProc(const char* name) : TGo4EventProcessor(name)
{
  cout << "**** TArtProc: Create instance " << name << endl;

  char dummy[64];
  char title[64];

  //  hTrigger = MakeTH1("Raw data", "newTrigger", 16, 0.5, 16.5); 
    fHis1  = MakeTH1('I',"His1","Data Segments",100,1,100,"Channels");
    fCoin  = MakeTH1('I',"fCoin","Coincidence Register",16,-0.5,15.5,"Channels");

    bool remove_histos = 0;

    // Yassid 220813 17:19
  for(int n=0;n<32;n++) {

  /*  hvmi01_0[n]  = MakeH1ISeries("Raw data/vmi01",  0, 0, n, remove_histos);
    hvmi01_1[n]  = MakeH1ISeries("Raw data/vmi01",  1, 0, n, remove_histos);
    hvmi01_2[n]  = MakeH1ISeries("Raw data/vmi01",  2, 0, n, remove_histos);
    hvmi01_3[n]  = MakeH1ISeries("Raw data/vmi01",  3, 0, n, remove_histos);
    hvmi01_4[n]  = MakeH1ISeries("Raw data/vmi01",  4, 0, n, remove_histos);
    hvmi01_6[n]  = MakeH1ISeries("Raw data/vmi01",  6, 0, n, remove_histos);
    hvmi01_7[n]  = MakeH1ISeries("Raw data/vmi01",  7, 0, n, remove_histos);
    hvmi01_8[n]  = MakeH1ISeries("Raw data/vmi01",  8, 0, n, remove_histos);
    hvmi01_9[n]  = MakeH1ISeries("Raw data/vmi01",  9, 0, n, remove_histos);
    hvmi01_10[n] = MakeH1ISeries("Raw data/vmi01", 10, 0, n, remove_histos);
    hvmi01_11[n] = MakeH1ISeries("Raw data/vmi01", 11, 0, n, remove_histos);
    hvmi01_12[n] = MakeH1ISeries("Raw data/vmi01", 12, 0, n, remove_histos); 
    hvmi01_13[n] = MakeH1ISeries("Raw data/vmi01", 13, 0, n, remove_histos);
    hvmi01_14[n] = MakeH1ISeries("Raw data/vmi01", 14, 0, n, remove_histos);
    hvmi01_15[n] = MakeH1ISeries("Raw data/vmi01", 15, 0, n, remove_histos);
    hvmi01_16[n] = MakeH1ISeries("Raw data/vmi01", 16, 0, n, remove_histos);
    hvmi01_17[n] = MakeH1ISeries("Raw data/vmi01", 17, 0, n, remove_histos);
    hvmi01_18[n] = MakeH1ISeries("Raw data/vmi01", 18, 0, n, remove_histos);
    hvmi01_19[n] = MakeH1ISeries("Raw data/vmi01", 19, 0, n, remove_histos);
    hvmi01_20[n] = MakeH1ISeries("Raw data/vmi01", 20, 0, n, remove_histos);*/

   /* hsva01_0[n]  = MakeH1ISeries("Raw data/sva01",  0, 1, n, remove_histos);
    hsva01_2[n]  = MakeH1ISeries("Raw data/sva01",  2, 1, n, remove_histos);
    hsva01_3[n]  = MakeH1ISeries("Raw data/sva01",  3, 1, n, remove_histos);
    hsva01_4[n]  = MakeH1ISeries("Raw data/sva01",  4, 1, n, remove_histos);
    hsva01_5[n]  = MakeH1ISeries("Raw data/sva01",  5, 1, n, remove_histos);
    hsva01_6[n]  = MakeH1ISeries("Raw data/sva01",  6, 1, n, remove_histos);
    hsva01_7[n]  = MakeH1ISeries("Raw data/sva01",  7, 1, n, remove_histos);
    hsva01_8[n]  = MakeH1ISeries("Raw data/sva01",  8, 1, n, remove_histos);
    hsva01_9[n]  = MakeH1ISeries("Raw data/sva01",  9, 1, n, remove_histos);*/
    //hsva01_10[n] = MakeH1ISeries("Raw data/sva01", 10, 1, n, remove_histos);
   // hsva01_11[n] = MakeH1ISeries("Raw data/sva01", 11, 1, n, remove_histos);
  /*  hsva01_12[n] = MakeH1ISeries("Raw data/sva01", 12, 1, n, remove_histos); 
    hsva01_13[n] = MakeH1ISeries("Raw data/sva01", 13, 1, n, remove_histos);
    hsva01_14[n] = MakeH1ISeries("Raw data/sva01", 14, 1, n, remove_histos);
    hsva01_15[n] = MakeH1ISeries("Raw data/sva01", 15, 1, n, remove_histos);
    hsva01_16[n] = MakeH1ISeries("Raw data/sva01", 16, 1, n, remove_histos);
    hsva01_17[n] = MakeH1ISeries("Raw data/sva01", 17, 1, n, remove_histos);
    hsva01_18[n] = MakeH1ISeries("Raw data/sva01", 18, 1, n, remove_histos);
    hsva01_19[n] = MakeH1ISeries("Raw data/sva01", 19, 1, n, remove_histos);
    hsva01_20[n] = MakeH1ISeries("Raw data/sva01", 20, 1, n, remove_histos);*/

    hv7768_0[n]  = MakeH1ISeries("Raw data/v7768",  0, 3, n, remove_histos);
    hv7768_1[n]  = MakeH1ISeries("Raw data/v7768",  1, 3, n, remove_histos);
    hv7768_2[n]  = MakeH1ISeries("Raw data/v7768",  2, 3, n, remove_histos);
    hv7768_3[n]  = MakeH1ISeries("Raw data/v7768",  3, 3, n, remove_histos);
    hv7768_4[n]  = MakeH1ISeries("Raw data/v7768",  4, 3, n, remove_histos);
   // hv7768_6[n]  = MakeH1ISeries("Raw data/v7768",  6, 3, n, remove_histos);
  //  hv7768_7[n]  = MakeH1ISeries("Raw data/v7768",  7, 3, n, remove_histos);
  //  hv7768_8[n]  = MakeH1ISeries("Raw data/v7768",  8, 3, n, remove_histos);
  //  hv7768_9[n]  = MakeH1ISeries("Raw data/v7768",  9, 3, n, remove_histos);
  //  hv7768_10[n] = MakeH1ISeries("Raw data/v7768", 10, 3, n, remove_histos);
 //   hv7768_11[n] = MakeH1ISeries("Raw data/v7768", 11, 3, n, remove_histos);
 //   hv7768_12[n] = MakeH1ISeries("Raw data/v7768", 12, 3, n, remove_histos); 
 //   hv7768_13[n] = MakeH1ISeries("Raw data/v7768", 13, 3, n, remove_histos);
  //  hv7768_14[n] = MakeH1ISeries("Raw data/v7768", 14, 3, n, remove_histos);
      hv7768_15[n] = MakeH1ISeries("Raw data/v7768", 15, 3, n, remove_histos);
      hv7768_16[n] = MakeH1ISeries("Raw data/v7768", 16, 3, n, remove_histos);
  //  hv7768_17[n] = MakeH1ISeries("Raw data/v7768", 17, 3, n, remove_histos);
 //   hv7768_18[n] = MakeH1ISeries("Raw data/v7768", 18, 3, n, remove_histos);
 //   hv7768_19[n] = MakeH1ISeries("Raw data/v7768", 19, 3, n, remove_histos);
 //   hv7768_20[n] = MakeH1ISeries("Raw data/v7768", 20, 3, n, remove_histos);

   
    //hsva02_6[n]  = MakeH1ISeries("Raw data/sva02",  6, 2, n, remove_histos);
   

   } 

  for(int n=0;n<128;n++) { //Raw data for v1190 modules Yassid 22082013 19:17

          //hvmi01_5[n]  = MakeH1ISeries("Raw data/vmi01_v1190",  5, 0, n, remove_histos);
         //  hsva01_10[n]  = MakeH1ISeries("Raw data/sva01_v1190",  10, 1, n, remove_histos);
	  // hsva02_4[n]   = MakeH1ISeries("Raw data/sva02_v1190",  4, 2, n, remove_histos);
	 //  hsva02_3[n]   = MakeH1ISeries("Raw data/sva02_v1190",  3, 2, n, remove_histos);
           hv7768_15[n] = MakeH1ISeries("Raw data/v7768", 15, 3, n, remove_histos);
           hv7768_16[n] = MakeH1ISeries("Raw data/v7768", 16, 3, n, remove_histos);
  }

  
  


  fcHis1 = MakeWinCond("cHis1",10,20);
  fcHis1->SetValues(200,1000);
  fcHis1->ResetCounts();
  // associate condition with histogram: histogram will be displayed
  // together with condition limits when condition editor is called
  fcHis1->SetHistogram("His1");
  fcHis1->Enable();

  cout << "**** TArtProc: Created objects" << endl;
  // Set values of parameter (once we have generated the macros):
  //   gROOT->ProcessLine(".x set_Par1.C()");
  //   gROOT->ProcessLine(".x set_cHis1.C(1,1,1)"); // flags, counters, reset


}


TH1* TArtProc::MakeH1ISeries(const char* foldername,
                                    Int_t seriesnumber,
                                    Int_t crate,
                                    Int_t number,
                                    Bool_t remove) {
  // char fullfoldername[100];                                    
  // sprintf(fullfoldername,"%s/%02d", foldername, seriesnumber);
  // cout<<fullfoldername<<endl;
 
  char fullfoldername[100];
  char histoname[100];
  if(crate==0){
  sprintf(fullfoldername,"%s/Module_%02d/vmi01_Mod%02d_Ch%02d", foldername,seriesnumber,seriesnumber, number);
  sprintf(histoname,"vmi01_Mod%02d_Ch%02d",seriesnumber, number);
  }
  else if(crate==1){
  sprintf(fullfoldername,"%s/Module_%02d/sva01_Mod%02d_Ch%02d", foldername,seriesnumber,seriesnumber, number);
  sprintf(histoname,"sva01_Mod%02d_Ch%02d",seriesnumber, number);
  }
  else if(crate==2){
  sprintf(fullfoldername,"%s/Module_%02d/sva02_Mod%02d_Ch%02d", foldername,seriesnumber,seriesnumber, number);
  sprintf(histoname,"sva02_Mod%02d_Ch%02d",seriesnumber, number);
  }
  else if(crate==3){
  sprintf(fullfoldername,"%s/Module_%02d/v7768_Mod%02d_Ch%02d", foldername,seriesnumber,seriesnumber, number);
  sprintf(histoname,"v7768_Mod%02d_Ch%02d",seriesnumber, number);
  }
 
  /* if (remove) {
    char fullname[200]; 
    sprintf(fullname,"%s/%s",fullfoldername,histoname);
    RemoveHistogram(fullname); 
    return 0;   
    } */

  //  if(crate==1 && seriesnumber==12)  
  //   return MakeH1I(fullfoldername, histoname, 5000, 0, 2097151);
  //  else
  // return MakeTH1('I',fullfoldername, histoname, 4096, 0, 4096);// This is OBSOLETE
  
  if(seriesnumber==5 && crate==0)  return MakeTH1('I',fullfoldername,histoname, 4000., 1., 50000.);
  else if(seriesnumber==10 && crate==1) return MakeTH1('I',fullfoldername,histoname, 4000., 1., 50000.);
  else if(seriesnumber==4 && crate==2) return MakeTH1('I',fullfoldername,histoname, 4000., 1., 50000.);
  else if((seriesnumber==15||seriesnumber==16) && crate==3) return MakeTH1('I',fullfoldername,histoname, 4000., 1., 50000.);
  else if(seriesnumber==8 && crate==3) return MakeTH1('I',fullfoldername,histoname,8192,1.,8191);
  else return MakeTH1('I',fullfoldername,histoname, 4096., 1., 4096.);
  
  
}



//-----------------------------------------------------------
// event function
Bool_t TArtProc::BuildEvent(TGo4EventElement* target)
{
 
    Bool_t isValid=kFALSE; // validity of output event

  TArtRawEventObject    * rawobj;
  TArtRawEvent    * raw;
  TArtRawSegmentObject *seg;
  TArtRawDataObject *d;

  raw = (TArtRawEvent* ) GetInputEvent();
  rawobj = (TArtRawEventObject *) raw->raweve;
  FillHistograms(rawobj);
  
    TArtUnpackEvent* out_evt = dynamic_cast<TArtUnpackEvent*> (target);
    
     if (raw==0) {
      cout << "TArtProc: no input event !"<< endl;
       out_evt->SetValid(isValid); // to store or not to store
      // default calling Fill method will set validity of out_evt to return value!
      return isValid;
      }
      // isValid=kTRUE;

        int full_info_debug=100000;


	

            Int_t nsegments = rawobj->GetNumSeg();
 
             fHis1->Fill(nsegments);
	   
 
 

         for(int i=0;i<nsegments;i++){
	       
	       
	       seg = rawobj->GetSegment(i);
	       int modid=seg->GetModule();
	       int detid=seg->GetDetector();
	  
	  
	   if(modid!=50){  
	      
	     /*  for(int j=0;j<seg->GetNumData();j++){            // Yassid 20112013 Useless
		 TArtRawDataObject *d = seg->GetData(j);
		 int geo = d->GetGeo(); 
		 int ch = d->GetCh();
		 int val = d->GetVal(); 
		 //	  cout<<ch<<"   "<<val<<endl;
		 //   fHisDID->Fill(ch);
		 //   fHisADC->Fill(val);
	       }*/
	       
	    
	       


            //********************************************* LUPO COINCIDENCE REGISTER ****************************************************//
	    
	    

	       if( LUPOIO == seg->GetModule()){

	               int det = seg->GetDetector();
	         

		   

			      if(det == 10){  // LUPO IO Coincidence register
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    //int val = d->GetVal();
                                    fCoin->Fill(ch);
				    
		    	            //cout<<"val  :"<<val<<"  ch  :"<<ch<<" J  :"<<j<<endl;
		                   
				 } // Data loop
			 } // Detector if 

			
  



	    
	    } // Module if v785  */





		//***********************************MYRIAD TIMESTAMP************************************//
               
	     if( MYRIAD == seg->GetModule()){
		int det = seg->GetDetector();

			 if(det==60){

				unsigned int ts0=0,ts1=0,ts2=0;
				unsigned long long int timestamp=0;
				
					for(int j=0;j<seg->GetNumData();j++)
					{
						TArtRawDataObject *d = seg->GetData(j);//get rawdata

						//int geo = d->GetGeo(); 
						int ch = d->GetCh();
 						
						unsigned int valts = d->GetVal();
						
						//int valtsi = (int) valts;

						//out_evt-> v7768[5][ch]=valts;
						// hv7768_5[ch]->Fill(valtsi);
					 
						
						//cout<<" Val : "<<std::hex<< setfill('0') << setw(2)<<valts<<" Ch  :"<<ch<<endl;
						

						if(ch==0){
							ts0 = (valts>>16)&0xffff;
							//ts1 = (valts<<16)&0xffff0000; // Yassid: I keep these lines as example of stupid thing 05-02-2015 17:31 JST
							//ts1 = (ts1>>16)&0x0000ffff;
							ts1 = valts&0xffff;							 

							 // cout<<" TS0 : "<<std::hex<<ts0<<" TS1 : "<<std::hex<<ts1<<endl;// Debug Yassid
							}		
						if(ch==1){
							 ts2 = valts&0xffff;
							 //cout<<" TS2 : "<<ts2<<endl; Debug Yassid	
							}


						
					}// GetNumData

                                                timestamp =  ts2&0xffff;
                                                timestamp = timestamp<<16;
                                                timestamp = timestamp + ts1;
						timestamp = timestamp<<16;
						timestamp = timestamp +ts0;

					

				}


		}// MYRIAD TS 

	       //********************************************* V792 **********************************//
	      if( V792 == seg->GetModule()){

	               int det = seg->GetDetector();
	         

		      /*  if(det == 42){  // 
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[4][ch]= val;
				    hsva01_4[ch]->Fill(val);
				    //    cout<<ch<<"   "<<val<<endl;
				 } // Data loop
			 } // Detector if*/
	      
		        /* if(det == 44){  // HODOQ2
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[19][ch]= val;
				    hsva01_19[ch]->Fill(val);
				 } // Data loop
			 } // Detector if


			  if(det == 45){  // HODOQ3
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[18][ch]= val;
				    hsva01_18[ch]->Fill(val);
				 } // Data loop
			 } // Detector if*/

		        /* if(det == 0){  // PPACQ
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva02[6][ch]= val;
				    hsva02_6[ch]->Fill(val);
				 } // Data loop
			 } // Detector if*/


			if(det == 2){  // 
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> v7768[0][ch]= val;
				    hv7768_0[ch]->Fill(val);
				 } // Data loop
			 } // Detector if*/

			if(det == 43){   
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> v7768[4][ch]= val;
				    hv7768_4[ch]->Fill(val);
				 } // Data loop
			 } // Detector if


	    
	    } // Module if v792


	    //********************************************* 785 ****************************************************//
	    
	    // SSD Detectors on F3 Crate Yassid 01062014 E407 For Beam tunning

	     /*  if( V785 == seg->GetModule()){

	               int det = seg->GetDetector();
	         

		   

			      if(det == 57){  // DSSDA12
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[11][ch]= val;
				    hsva01_11[ch]->Fill(val);
				 } // Data loop
			 } // Detector if 

			
  



	    
	    } // Module if v785  */



		//************************************* 775 **************************************//

	      //  if( V775 == seg->GetModule()){   /

	              //  int det = seg->GetDetector();
	         

		     /*  if(det == 40 ){  // ENF2TDC1
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[8][ch]= val;
				    hsva01_8[ch]->Fill(val);
		                    
				 } // Data loop
			 } // Detector if*/
	      
		       /*  if(det == 41 ){  // HODOT2
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[15][ch]= val;
			if(edge==0){
					        		out_evt-> sva02_tdc[4][ch][mhitl[ch]]= val;
					   			hsva02_4[ch]->Fill(val);
					    			mhitl[ch]++;
								}	    hsva01_15[ch]->Fill(val);
				 } // Data loop
			 } // Detector if
			 
			 
			 if(det == 38 ){  // HODOT3
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> sva01[14][ch]= val;
				    hsva01_14[ch]->Fill(val);
				 } // Data loop
			 } // Detector if


			  if(det == 1 ){  // PPACT
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> vmi01[4][ch]= val;
				    hvmi01_4[ch]->Fill(val);
				 } // Data loop
			 } // Detector if*/

		        
		 // } // Module if v775

		  //*************************** v1190  ***********************//

		  if( V1190 == seg->GetModule()){

	                int det = seg->GetDetector();
	         

		/*       if(det == 42 ){  // HODOTADD
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();

				    //   cout<<"val  :"<<val<<"  ch  :"<<ch<<" J  :"<<j<<endl;
		    
		                    out_evt-> sva01_tdc[1][ch]= val;gmulti
		                    hsva01_1[ch]->Fill(val);
				 } // Data loop
			 } // Detector if*/
	      
		      /*   if(det == 43 ){  // SSDT
		                 
			     for(int p=0;p<100;p++) mhit[p]=0;
				
				 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
				    
				    int qq=seg->GetNumData();
				    
				   //cout<<" GetumData  : "<<qq<<" J  :"<<j<<"  val  :"<<val<<"  ch  :"<<ch<<endl;
		    
		    	
		                  
				   
		    	        
				    // Yassid 061013 ensure multiplicity 1 for PPAC
		                   
				    if(ch!=12 || ch!=14){
				    	if(mhit[ch]<1){
				    	out_evt-> sva01_tdc[10][ch][mhit[ch]]= val;
				   	 hsva01_10[ch]->Fill(val);
				    	mhit[ch]++;
					
				    	//if(ch==14 || ch==12) cout<<" GetumData  : "<<qq<<" J  :"<<j<<"  val  :"<<val<<"  ch  :"<<ch<<"mhit  :"<<mhit[ch]<<endl;
				    }
				    else if(ch==12 || ch==14){  // This was probably done to store  RF signals
				    
				         out_evt-> sva01_tdc[10][ch][0]= val;
				    	 hsva01_10[ch]->Fill(val);
					
					// cout<<" GetumData  : "<<qq<<" J  :"<<j<<"  val  :"<<val<<"  ch  :"<<ch<<"mhit  :"<<mhit[ch]<<endl;
				    	}
				     
				    }
				    
				    
				    
				 } // Data loop
			 } // Detector if*/
			 
			 
			    if(det == 3 ){  // 
			    	
		                 
			     for(int p=0;p<128;p++){ mhitl[p]=0;mhitt[p]=0;}
				
				 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
				    
				    int qq=seg->GetNumData();
		
		                    //if(ch>100) cout<<"ch :"<<ch<<"  val : "<<val<<endl;
				   
					int edge=d->GetEdge();
					//cout<< " Ev : "<<j<<  " Edge : "<<edge<<" Channel : "<<ch<<" Value "<<val<<endl;
											
					    		if(mhitl[ch]<10){ //Leading
					    		

								
								if(edge==0){ 
					        		out_evt-> v7768_tdc[15][ch][mhitl[ch]]= val;
					   			hv7768_15[ch]->Fill(val);
					    			mhitl[ch]++;
								}

							}

							if(mhitt[ch]<10){ //Trailing

								if(edge==1){
					        		out_evt-> v7768_tdc[16][ch][mhitt[ch]]= val;
					   			hv7768_16[ch]->Fill(val);
					    			mhitt[ch]++;
								}
				    	
				     
				   
				     
				    			}
				    
				    
				    
				 } // Data loop
			 } // Detector if


		        
		  } // Module if v1190  


		  //*********************** MADC **************************//


		   if(  MADC32 == seg->GetModule()){

	               int det = seg->GetDetector();
	         

		         if(det == 40 ){  // CAGRAE1
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> v7768[1][ch]= val;
		                    hv7768_1[ch]->Fill(val);
				 } // Data loop
			 } // Detector if
	      
		         if(det == 41 ){  // SSDE
		                 for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> v7768[2][ch]= val;
				    hv7768_2[ch]->Fill(val);
				 } // Data loop
			 } // Detector if


			  if(det == 42 ){  // SSDE
		                for(int j=0;j<seg->GetNumData();j++){
		                    d = seg->GetData(j);
		                    int ch = d->GetCh();
		                    int val = d->GetVal();
		    
		                    out_evt-> v7768[3][ch]= val;
				    hv7768_3[ch]->Fill(val);
				 } // Data loop
			 } // Detector if

		        
		  } // Module if MADC
		  
		  		  
	 } // End of modid!=50  




     } // Segment loop

  
  	
      

 

     


  return kTRUE;
}

//-----------------------------------------------------------
// histogramming function
Bool_t TArtProc::FillHistograms(TArtRawEventObject* event)
{
  /*   Int_t nsegments = event->GetNumSeg();
  fHis1->Fill(nsegments);
  for(int i=0;i<nsegments;i++){
    TArtRawSegmentObject *seg = event->GetSegment(i);
    for(int j=0;j<seg->GetNumData();j++){
      TArtRawDataObject *d = seg->GetData(j);
      int geo = d->GetGeo(); 
      int ch = d->GetCh();
      int val = d->GetVal(); 
      //   fHisDID->Fill(ch);
      //   fHisADC->Fill(val);
    }

    if( V792 == seg->GetModule()){
      int det = seg->GetDetector();
      if(det == 45){
	for(int j=0;j<seg->GetNumData();j++){
	   TArtRawDataObject *d = seg->GetData(j);
	  int ch = d->GetCh();
	  int val = d->GetVal();
	  //raw[1]->Fill(ch,val);
	   hvmi01_0[ch]->Fill(val);
	}
      }
    }

    }*/

  return kTRUE;
}
//----------------------------END OF GO4 SOURCE FILE ---------------------
