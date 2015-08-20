#include"ComparableObject.hpp"

int main(){
  ComparableObject* LHCbNew= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/LHCbNew_RMSResults.root","LHCb_New");
  TGraphErrors* Try = LHCbNew->GetTheta0(kRed);

  TFile* Out= new TFile("Output.root","RECREATE");
  Try->Write();

}
