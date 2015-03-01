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

#include "TArtAnalysis.h"

#include <stdlib.h>
#include "Riostream.h"

#include "Go4EventServer.h"
#include "TGo4StepFactory.h"
#include "TGo4AnalysisStep.h"
#include "TGo4Version.h"

//***********************************************************
TArtAnalysis::TArtAnalysis(){}

//***********************************************************
// this constructor is called by go4analysis executable
TArtAnalysis::TArtAnalysis(int argc, char** argv) : TGo4Analysis(argc, argv)
{
   cout << "**** Create TArtAnalysis " << argv[0] << endl;

   if (!TGo4Version::CheckVersion(__GO4BUILDVERSION__)) {
      cout << "****  Go4 version mismatch" << endl;
      exit(-1);
   }

   TGo4StepFactory*	factory1 = new TGo4StepFactory("Factory1");
   TGo4AnalysisStep*	step1	 = new TGo4AnalysisStep("Unpack", factory1, 0, 0);
   AddAnalysisStep(step1);
   
   factory1->DefUserEventSource("TArtEventSource");
   factory1->DefInputEvent("RawEvent","TArtRawEvent");
   factory1->DefEventProcessor("Proc1","TArtProc");
   factory1->DefOutputEvent("UnpackEvent","TArtUnpackEvent");

   //   TGo4UserSourceParameter* source = new TGo4UserSourceParameter("/root/e390/ridf_osatsu/data0063.ridf"); // FOR OFF LINE
   TGo4UserSourceParameter*	source = new TGo4UserSourceParameter("lawrencium","",10080);	// For osatsu
    // TGo4UserSourceParameter* source = new TGo4UserSourceParameter("192.168.3.4","",10080); // For osatsulan
   step1->SetEventSource(source);	// register event source
   step1->SetSourceEnabled(kTRUE);
   step1->SetProcessEnabled(kTRUE);
   step1->SetErrorStopEnabled(kTRUE);


   TGo4StepFactory*	factory2 = new TGo4StepFactory("Factory2");
   TGo4AnalysisStep*	step2	 = new TGo4AnalysisStep("Sort", factory2, 0, 0);
   AddAnalysisStep(step2);

   factory2->DefInputEvent("UnpackEvent","TArtUnpackEvent");
   factory2->DefEventProcessor("Proc2","TArtSortProc");
   factory2->DefOutputEvent("SortEvent", "TArtSortEvent");

   //  TGo4UserSourceParameter* source = new TGo4UserSourceParameter("test.ridf");
   step2->SetProcessEnabled(kTRUE);
   step2->SetErrorStopEnabled(kTRUE);


   TGo4StepFactory*	factory3 = new TGo4StepFactory("Factory3");
   TGo4AnalysisStep*	step3	 = new TGo4AnalysisStep("Analysis", factory3, 0, 0);
   AddAnalysisStep(step3);

   factory3->DefInputEvent("SortEvent","TArtSortEvent");
   factory3->DefEventProcessor("Proc3","TArtAnlProc");
   factory3->DefOutputEvent("AnlEvent", "TArtAnlEvent");

  
   step3->SetProcessEnabled(kFALSE);
   step3->SetErrorStopEnabled(kFALSE);
   
   SetAutoSave(kFALSE);


   Print();			// print setup

   // Define custom passwords for analysis server
   DefineServerPasswords("Artadmin", "Artcontrol", "Artview");

}

//***********************************************************
TArtAnalysis::~TArtAnalysis()
{
   cout << "**** TArtAnalysis: Delete instance" << endl;
}

//-----------------------------------------------------------
Int_t TArtAnalysis::UserPreLoop()
{
   // called after start analysis before first event
   cout << "**** TArtAnalysis: PreLoop" << endl;
   Print();			// print setup
   return 0;
}
//-----------------------------------------------------------
Int_t TArtAnalysis::UserPostLoop()
{
   // called after close analysis after last  event
   // all this is optional:
   cout << "**** TArtAnalysis: PostLoop" << endl;
   return 0;
}

//-----------------------------------------------------------
Int_t TArtAnalysis::UserEventFunc()
{
   // all this is optional:
   // This function is called once for each event after all steps.
   return 0;
}
