#include"SixSimRun.hpp"

SixSimRun::SixSimRun(std::string _DataFileName,std::string _Name):ComparableObject(_DataFileName,_Name){
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
    std::string LeadProfileName="11;"+std::to_string(i);
    TH1D* LeadProfile=(TH1D*)DataFile->Get(LeadProfileName.data());
    assert(LeadProfile!=NULL);
    LeadProfile->SetDirectory(0);
    std::string ScintProfileName="12;"+std::to_string(i);
    TH1D* ScintProfile= (TH1D*)DataFile->Get(ScintProfileName.data());
    assert(ScintProfile!=NULL);
    ScintProfile->SetDirectory(0);
    LeadShowerProfiles.insert(std::make_pair(std::to_string(i),LeadProfile));
    ScintShowerProfiles.insert(std::make_pair(std::to_string(i),ScintProfile));
  }
}

SixSimRun::~SixSimRun(){std::cout<<"SixSim destructor Called"<<std::endl;}
