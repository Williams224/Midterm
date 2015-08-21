#include"ComparableObject.hpp"
#include"Comparison.hpp"

int main(){
  ComparableObject* LHCbNew= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/LHCbNew_RMSResults.root","LHCb_New");
  ComparableObject* opt1 = new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/opt1_RMSResults.root","opt1");
  TGraphErrors* Try = LHCbNew->GetTheta0(kRed);
  Comparison* CTry= new Comparison("Random");
  CTry->SetBaseLine(LHCbNew);
  CTry->AddSimRun(opt1);
  TFile* Out= new TFile("Output.root","RECREATE");
  Try->Write();
  CTry->WriteTheta0();
  

}
