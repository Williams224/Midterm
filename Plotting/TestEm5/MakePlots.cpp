#include"ComparableObject.hpp"
#include"Comparison.hpp"

int main(){
  ComparableObject* LHCbNew= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/LHCbNew_RMSResults.root","LHCb_New");
  ComparableObject* opt3 = new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/opt3_RMSResults.root","opt3");
  ComparableObject* LHCbOld= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/v9.5LHCbOld_RMSResults.root","LHCb_Old");
  TGraphErrors* Try = LHCbNew->GetTheta0(kRed);
  Comparison* CTry= new Comparison("Random");
  CTry->SetBaseLine(LHCbOld);
  CTry->AddSimRun(LHCbNew);
  CTry->AddSimRun(opt3);
  TFile* Out= new TFile("Output.root","RECREATE");
  Try->Write();
  CTry->WriteTheta0();
  

}
