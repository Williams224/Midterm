#include"FiveSimRun.hpp"

FiveSimRun::FiveSimRun(std::string _DataFileName,std::string _Name):ComparableObject(_DataFileName,_Name){
  StraightRes=(TGraphErrors*)DataFile->Get("Resolution1;1");
  assert(StraightRes!=NULL);
  CurvedRes=(TGraphErrors*)DataFile->Get("Resolution2;1");
  assert(CurvedRes!=NULL);
  ScintSampling=(TGraphErrors*)DataFile->Get("ScintSampling;1");
  assert(ScintSampling!=NULL);
  LeadSampling=(TGraphErrors*)DataFile->Get("LeadSampling;1");
  assert(LeadSampling!=NULL);
  SamplingRatio=(TGraphErrors*)DataFile->Get("Sampling");
  for(int i=1;i<=13;++i){
    std::string LeadProfileName="ScaledAbsorberOneProfile;"+std::to_string(i);
    TH1D* LeadProfile= (TH1D*)DataFile->Get(LeadProfileName.data());
    assert(LeadProfile!=NULL);
    std::string ScintProfileName="ScaledAbsorberTwoProfile;"+std::to_string(i);
    TH1D* ScintProfile= (TH1D*)DataFile->Get(ScintProfileName.data());
    assert(ScintProfile!=NULL);
    LeadShowerProfiles.insert(std::make_pair(std::to_string(i),LeadProfile));
    ScintShowerProfiles.insert(std::make_pair(std::to_string(i),ScintProfile));
  }
  std::cout<<"Five Sim object constructor called"<<std::endl;
}

FiveSimRun::~FiveSimRun(){std::cout<<"FiveSim Destructor Called"<<std::endl;}
std::map<std::string,TH1D*> FiveSimRun::GetLeadShowerProfiles(){return LeadShowerProfiles;}
std::map<std::string,TH1D*> FiveSimRun::GetScintShowerProfiles(){return ScintShowerProfiles;}

void FiveSimRun::WriteAll(){
}
  
