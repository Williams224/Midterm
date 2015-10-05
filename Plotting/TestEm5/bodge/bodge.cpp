#include"TCanvas.h"
#include"TFile.h"
#include"TH1D.h"
#include"TMath.h"
#include<assert.h>
#include"TGraphErrors.h"
#include"TMultiGraph.h"
#include"TLegend.h"

int main(){
  
  TFile* InOldFile= new TFile("OutputOld.root");
  assert(InOldFile!=NULL);
  TGraphErrors* InOld=(TGraphErrors*)InOldFile->Get("Graph");
  TFile* InNewFile= new TFile("Output.root");
  assert(InNewFile!=NULL);
  TGraphErrors* InNew=(TGraphErrors*)InNewFile->Get("Graph");
  TFile* In95File= new TFile("v9.5Output.root");
  assert(In95File!=NULL);
  TGraphErrors* In95=(TGraphErrors*)In95File->Get("Graph");
  Double_t* OldE=InOld->GetX();
  Double_t* NewE=InNew->GetX();
  Double_t* E95=In95->GetX();
  Double_t* OldR=InOld->GetY();
  Double_t* NewR=InNew->GetY();
  Double_t* R95=In95->GetY();
  Double_t* OldUR=InOld->GetEY();
  Double_t* NewUR=InNew->GetEY();
  Double_t* UR95=In95->GetEY();
  Double_t OldNormed[13];
  Double_t NewNormed[13];
  Double_t OldNormedU[13];
  Double_t NewNormedU[13];
  int N=13;
  for(int n=0;n<N;++n){
    OldNormed[n]=OldR[n]/R95[n];
    NewNormed[n]=NewR[n]/R95[n];
    double OldU=OldUR[n];
    double NewU=NewUR[n];
    double U95=UR95[n];
    double N=R95[n];
    double E1=OldU/N;
    double E2=(U95*OldR[n])/(N*N);
    OldNormedU[n]=TMath::Sqrt((E1*E1)+(E2*E2));
    double NewE1=NewU/N;
    double NewE2=(U95*NewR[n])/(N*N);
    NewNormedU[n]=TMath::Sqrt((NewE1*NewE1)+(NewE2*NewE2));
  }
  TGraphErrors* New= new TGraphErrors(N,NewE,NewNormed,0,NewNormedU);
  TGraphErrors* Old= new TGraphErrors(N,OldE,OldNormed,0,OldNormedU);
  New->SetMarkerColor(kRed);
  Old->SetMarkerColor(kBlue);
  New->SetLineColor(kRed);
  Old->SetLineColor(kBlue);
  TMultiGraph* MG= new TMultiGraph();
  MG->Add(New,"AP");
  MG->Add(Old,"AP");
  MG->SetTitle("Theta0 Comparison;Energy/MeV;#theta /v9.5 LHCbOld #theta");
  TLegend* Leg=new TLegend(0.1,0.7,0.48,0.9);
  Leg->AddEntry(New,"v9.6 LHCbNew","PL");
  Leg->AddEntry(Old,"v9.6 LHCbOld","PL");
  TCanvas*C = new TCanvas();
  MG->Draw("AP");
  Leg->Draw();
  TFile* Out= new TFile("BodgedOutput.root","RECREATE");
  New->Write();
  Old->Write();
  MG->Write();
  C->Write();



}
