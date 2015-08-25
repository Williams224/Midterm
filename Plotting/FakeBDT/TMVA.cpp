#include"TMVA/Factory.h"
#include"TMVA/Tools.h"
//#include"TMVA/ROCCalc.h"
#include"TMVA/Ranking.h"
#include"TMVA/Reader.h"
#include"TFile.h"
#include"TTree.h"
#include"TCut.h"
#include"TMath.h"
#include"TProfile.h"
#include"TH2D.h"
#include"MVariable.hpp"
#include"MVariableArray.hpp"
#include"MultiVariable.hpp"
#include"BranchHandler.hpp"
#include<vector>
#include"TRandom3.h"
#include"TBranch.h"
#include"FillableGraph.hpp"
#include"TCanvas.h"
#include"TLegend.h"

#include"FileHandler.hpp"

int main(int argc,char** argv){
  typedef std::vector<VMVariable*> VariableContainer;
  TFile* outputfile= new TFile("tmvaresults.root","RECREATE");
  TMVA::Tools::Instance();
  TMVA::Factory *factory = new TMVA::Factory("TMVAClassification",outputfile,"V:!Silent:Color:Transformations=I:DrawProgressBar:AnalysisType=Classification");
  Double_t SignalWeight=1.0;
  Double_t BackgroundWeight=1.0;
  TTree*SignalTreeTrain= new TTree("SignalTreeTrain","SignalTreeTrain");
  TTree*SignalTreeTest= new TTree("SignalTreeTest","SignalTreeTest");
  TTree*BackgroundTreeTest= new TTree("BackgroundTreeTest","BackgroundTreeTest");
  TTree*BackgroundTreeTrain=new TTree("BackgroundTreeTrain","BackgroundTreeTrain");
  double x1,x2,x3,x4;
  double y1,y2,y3,y4;
  TBranch* BX1=SignalTreeTrain->Branch("x",&x1,"x/D");
  TBranch* BY1=SignalTreeTrain->Branch("y",&y1,"y/D");
  TBranch* BX2=SignalTreeTest->Branch("x",&x2,"x/D");
  TBranch* BY2= SignalTreeTest->Branch("y",&y2,"y/D");
  TBranch* BX3= BackgroundTreeTest->Branch("x",&x3,"x/D");
  TBranch* BY3= BackgroundTreeTest->Branch("y",&y3,"y/D");
  TBranch* BX4= BackgroundTreeTrain->Branch("x",&x4,"x/D");
  TBranch* BY4= BackgroundTreeTrain->Branch("y",&y4,"y/D");

  //  FillableGraph* SigScatter=new FillableGraph("SigScatter");
  TH2D* SigScatter= new TH2D("SigScatter","A scatter plot of X against Y for signal and background events;X;Y",2400,0,2,2400,0,2);
  TH2D* BackScatter= new TH2D("BackScatter","BackScatter",2400,0,2,2400,0,2);
  TRandom3 R;
  int ns=120000;
  for(int i=0;i<ns;++i){
    if(i<((ns*2)/3)){
      x1=R.Rndm()*1.25;
      x2=R.Rndm()*1.25;
      y1=R.Rndm()*1.1;
      y2=R.Rndm()*1.1;
    }
    else{
      x1=(R.Rndm()*0.8)+1.2;
      x2=(R.Rndm()*0.8)+1.2;
      y1=(R.Rndm()*1.1)+0.9;
      y2=(R.Rndm()*1.1)+0.9;
      std::cout<<"x1 = "<<x1<<std::endl;
    }
    if(i<((ns*1)/3)){
      y3=R.Rndm()*1.1;
      y4=R.Rndm()*1.1;
      x3=(R.Rndm()*0.8)+1.2;
      x4=(R.Rndm()*0.8)+1.2;
    }else{
      y3=(R.Rndm()*1.1)+0.9;
      y4=(R.Rndm()*1.1)+0.9;
      x3=R.Rndm()*1.25;
      x4=R.Rndm()*1.25;
    }
    //std::cout<<x1<<std::endl;
    /*BX1->Fill();
    BX2->Fill();
    BX3->Fill();
    BX4->Fill();
    BY1->Fill();
    BY2->Fill();
    BY3->Fill();
    BY4->Fill();*/
    SigScatter->Fill(x1,y1);
    BackScatter->Fill(x3,y3);
    SignalTreeTrain->Fill();
    SignalTreeTest->Fill();
    BackgroundTreeTrain->Fill();
    BackgroundTreeTest->Fill();
  }
  std::cout<<"got Here"<<std::endl;
  TCanvas C;
  TLegend Leg(0.6,0.6,0.9,0.9);
  SigScatter->SetMarkerColor(kBlue);
  SigScatter->SetFillColor(kBlue);
  SigScatter->Draw();
  BackScatter->SetMarkerColor(kRed);
  BackScatter->SetFillColor(kRed);
  BackScatter->Draw("SAME");
  Leg.AddEntry(SigScatter,"Signal","f");
  Leg.AddEntry(BackScatter,"Background","f");
  Leg.Draw();
  C.Write();
  SignalTreeTrain->Write();
  factory->AddSignalTree(SignalTreeTrain,SignalWeight,"Train");
  factory->AddSignalTree(SignalTreeTest,SignalWeight,"Test");
  factory->AddBackgroundTree(BackgroundTreeTrain,BackgroundWeight,"Train");
  factory->AddBackgroundTree(BackgroundTreeTest,BackgroundWeight,"Test");
// /----------------------------------------Apply Cuts-------------------------------

// --------------------------------------------------Declare Variables---------------
  VariableContainer VariableList;
  MVariable* x=new MVariable("x",F,none);
  VariableList.push_back(x);
  MVariable* y= new MVariable("y",F,none);
  VariableList.push_back(y);

  //------------------------------Add Variables===============================
 VariableContainer::iterator A=VariableList.begin();
 for(;A!=VariableList.end();++A){
   factory->AddVariable((*A)->GetFactoryName(),(*A)->GetType());
 }
 TCut truthcut= "";
 TCut backgroundcut= "";
  factory->PrepareTrainingAndTestTree(truthcut,backgroundcut,"random");
  
  factory->BookMethod(TMVA::Types::kBDT,"BDT","NTrees=1:MaxDepth=2");
    
  factory->TrainAllMethods();
  
  factory->TestAllMethods();
  
  factory->EvaluateAllMethods();

  TMVA::Ranking * Ranks = new TMVA::Ranking();
  Ranks->Print();

  outputfile->Close();
  TFile*Analyse;
  Analyse= new TFile("tmvaresults.root");
  TH1D* ROC = (TH1D*)Analyse->Get("Method_BDT/BDT/MVA_BDT_trainingRejBvsS");
  Double_t Integ=ROC->Integral();
  std::cout<<"The ROC integral = "<<Integ<<std::endl;
  Analyse->Close();

}
