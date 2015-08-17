#include"FiveSimRun.hpp"

int main(){
  FiveSimRun opt1("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/95/LHCbOld_Save95.root","opt1");
  TFile* Out = new TFile("Output.root","RECREATE");
  TGraphErrors* Gopt1=opt1.GetStraightRes(kRed+2);
  TGraphErrors* Curvedopt1=opt1.GetCurvedRes(kMagenta+3);
  TGraphErrors* SRopt1=opt1.GetSamplingRatio(kGreen+2);
  TGraphErrors* ScintSamplingopt1=opt1.GetScintSampling(kOrange+8);
  std::map<std::string,TH1D*> LeadShowers=opt1.GetLeadShowerProfiles(kRed);
  Gopt1->Write();
  Curvedopt1->Write();
  SRopt1->Write();
  ScintSamplingopt1->Write();
  for(auto i=LeadShowers.begin();i!=LeadShowers.end();++i){
    i->second->Write();
  }


}
