#ifndef SPARF3_H
#define SPARF3_H

#include	"TGo4Parameter.h"
#include "TArrayI.h"
//#include "TArrayF.h"

class TArtF3Param : public TGo4Parameter {
 public:
  TArtF3Param();
  TArtF3Param(const char* name);
  virtual ~TArtF3Param();
  virtual Int_t		PrintParameter(Text_t * n, Int_t);
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
   
       Float_t	fF3UPPAC_tdc_ns2mm[5];	//U PPAC ns to mm
       Float_t	fF3DPPAC_tdc_ns2mm[5];	//D PPAC ns to mm

      // Yassid 11092013 Parameters for PPAC calibration
       
        Float_t fF3UPPAC_tdc_param[5];	//U PPAC ch to ns
        Float_t fF3DPPAC_tdc_param[5];	//D PPAC ch to ns
	
	//	Float_t fF3UPPAC_e390_offset[2];	//U PPAC e390 offset
	//      Float_t fF3DPPAC_e390_offset[2];	//D PPAC e390 offset 
        
	Float_t zpos[11];	//Positions

	ClassDef(TArtF3Param,1)
	  };

#endif //SPAR_H

//----------------------------END OF GO4 SOURCE FILE ---------------------
