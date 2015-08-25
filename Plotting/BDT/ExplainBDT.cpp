#include"TFile.h"
#include"TTree.h"
#include"TH2D.h"
#include"TMath.h"
#include<assert.h>
#include"TCanvas.h"
#include"FillableGraph.hpp"

int main(){

  TFile * SignalFile = new TFile("/Users/Tim/PhD/Analysis/eta_3pi_kstar/Data/mc/MC_12_MagAll_kstar_eta_3pi_BDTBoth.root");
  assert(SignalFile!=NULL);
  TTree* InTree=(TTree*)SignalFile->Get("DecayTree");
  assert(InTree!=NULL);
  TFile* BackFile= new TFile("/Users/Tim/PhD/Analysis/eta_3pi_kstar/Data/data/Data_12_MagAll_kstar_eta_3pi_BDTCut.root");
  assert(BackFile!=NULL);
  TTree* BackTree=(TTree*)BackFile->Get("DecayTree");
  assert(BackTree!=NULL);
  double SigDira;
  InTree->SetBranchAddress("B0_DIRA_OWNPV",&SigDira);
  double SigEta;
  InTree->SetBranchAddress("B0_eta",&SigEta);
  double BackDira;
  BackTree->SetBranchAddress("B0_DIRA_OWNPV",&BackDira);
  double BackEta;
  BackTree->SetBranchAddress("B0_eta",&BackEta);
  double B0_MM;
  BackTree->SetBranchAddress("B0_MM",&B0_MM);
  double backgamma_pt;
  BackTree->SetBranchAddress("gamma_PT",&backgamma_pt);
  double siggamma_pt;
  InTree->SetBranchAddress("gamma_PT",&siggamma_pt);
  FillableGraph* Sig= new FillableGraph("Signal");
  FillableGraph* Back = new FillableGraph("Back");
  
  Long64_t N=InTree->GetEntries();
  Long64_t BN=BackTree->GetEntries();
  TH2D* Scatter= new TH2D("Scatter","Scatter",200,-22,-7,200,0.0,4000.0);
  TH2D* BackScatter= new TH2D("BackScatter","BackScatter",200,-22,-7,200,0.0,4000.0);
  for(int i=0;i<N;++i){
    InTree->GetEntry(i);
    BackTree->GetEntry(i);
    Scatter->Fill(TMath::Log(1-SigDira),siggamma_pt);
    Sig->Fill(TMath::Log(1-SigDira),backgamma_pt,0,0);
    
    if(B0_MM<5100.0)BackScatter->Fill(TMath::Log(1-BackDira),backgamma_pt);
    if(B0_MM>5500.0)Back->Fill(TMath::Log(1-BackDira),BackEta,0,0);

  }
 
  TFile* Out = new TFile("Output.root","RECREATE");
  Scatter->SetMarkerColor(kRed);
  Scatter->Write();
  BackScatter->Write();
  TCanvas C;
  TGraphErrors*DrawableBack=Back->Data();
  DrawableBack->Draw("AP");
  C.Write();
  TCanvas C2;
  Scatter->Draw();
  BackScatter->Draw("SAME");
  C2.Write();
}
