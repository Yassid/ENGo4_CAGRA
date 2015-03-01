#ifndef SPARF2_H
#define SPARF2_H

#include	"TGo4Parameter.h"

#include "TArrayI.h"
//#include "TArrayF.h"

class TArtF2Param : public TGo4Parameter {
   public:
      TArtF2Param();
      TArtF2Param(const char* name);
      virtual ~TArtF2Param();
      virtual Int_t	PrintParameter(Text_t * n, Int_t);
      Int_t		PrintParameter();
      virtual Bool_t	UpdateFrom(TGo4Parameter *);

      Bool_t	fFill;		// enable filling histograms 
      Bool_t	fOutput;	// enable filling TArt event
      Float_t	fOffset;	// offset used for unpack
      Float_t	fFactor;	// factor used for unpack
      
      Float_t	frP1;		// Offset for calibration
      Float_t	frP2;		// Factor for Calibration
      Bool_t	fbHisto;	// Enable Histogramming
      
      TArrayI	fArr;		// example of usage of array in the parameter 
   
       Float_t	fF2UPPAC_tdc_ns2mm[5];	//U PPAC ns to mm
       Float_t	fF2DPPAC_tdc_ns2mm[5];	//D PPAC ns to mm

      // Yassid 11092013 Parameters for PPAC calibration
       
        Float_t fF2UPPAC_tdc_param[5];	//U PPAC ch to ns
        Float_t fF2DPPAC_tdc_param[5];	//D PPAC ch to ns

	// TETSUYA 20140529 change 
	//	Float_t fF2UPPAC_e390_offset[2];	//U PPAC e390 offset
	//      Float_t fF2DPPAC_e390_offset[2];	//D PPAC e390 offset 
	
	Float_t zpos[11];	//Positions
       

	/* // TETSUYA ADD 28052014  */
	/*  Float_t	fF3UPPAC_tdc_ns2mm[5];	//U PPAC ns to mm */
	/*  Float_t	fF3DPPAC_tdc_ns2mm[5];	//D PPAC ns to mm */
	/*  Float_t	fF3UPPAC_tdc_param[5];	//U PPAC ch to ns */
	/*  Float_t	fF3DPPAC_tdc_param[5];	//D PPAC ch to ns */

	 /* Float_t fF2UPPAC_X_slope;	//  PPAC ns to mm
	    Float_t fF2UPPAC_Y_slope;
	    Float_t fF2DPPAC_X_slope;
	    Float_t fF2DPPAC_Y_slope;
	    
	    Float_t fF2UPPAC_X_offset;
	    Float_t fF2UPPAC_Y_offset;
	    Float_t fF2DPPAC_X_offset;
	    Float_t fF2DPPAC_Y_offset;*/
	 
   ClassDef(TArtF2Param,1)
};

#endif //SPAR_H

//----------------------------END OF GO4 SOURCE FILE ---------------------
