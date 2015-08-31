#include"ComparableObject.hpp"
#include"Comparison.hpp"

int main(){
  ComparableObject* LHCbNew= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/LHCbNew_RMSResults.root","v9.6 New MSc Model");
  ComparableObject* LHCbOld= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/LHCbOld_RMSResults.root","v9.6 Old MSc Model");
  ComparableObject* opt0 = new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/opt0_RMSResults.root","opt0");
  ComparableObject* opt3 = new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/opt3_RMSResults.root","opt3");
  ComparableObject* opt1 = new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/opt1_RMSResults.root","opt1");
  ComparableObject* v95LHCbOld= new ComparableObject("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm5/v9.5LHCbOld_RMSResults.root","95LHCb_Old");
  TGraphErrors* Try = LHCbNew->GetTheta0(kRed);
  Comparison* CTry= new Comparison("Random");
  CTry->SetBaseLine(v95LHCbOld);
  CTry->AddSimRun(LHCbNew);
  //  CTry->AddSimRun(95LHCbOld);
  CTry->AddSimRun(LHCbOld);
  //  CTry->AddSimRun(opt1);
  //  CTry->AddSimRun(opt3);
  TFile* Out= new TFile("Output.root","RECREATE");
  Try->Write();
  CTry->WriteTheta0();
  

}
