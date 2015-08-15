#include"FiveSimRun.hpp"

FiveSimRun::FiveSimRun(std::string _DataFileName,std::string _Name):ComparableObject(_DataFileName,_Name){
  StraightRes=(TGraphErrors*)DataFile->Get("Resolution1");
  assert(StraightRes!=NULL);
  CurvedRes=(TGraphErrors*)DataFile->Get("Resolution2");
  assert(CurvedRes!=NULL);
  SamplingRatio=(TGraphErrors*)DataFile->Get("ScintSampling");
  assert(SamplingRatio!=NULL);
  ScintSampling=(TGraphErrors*)DataFile->Get("LeadSampling");
  assert(LeadSampling!=NULL);
  SamplingRatio=(TGraphErrors*)DataFile->Get("Sampling");
  for(int i=1;i<=13;++i){
    std::string LeadProfileName="ScaledAbsorberOneProfile;"+std::to_string(i);
    TH1D* LeadProfile= (TH1D*)DataFile->Get(LeadProfileName.data());
    assert(LeadProfile!=NULL);
    std::string ScintProfileName="ScaledAbsorberTwoProfile;"+std::to_string(i);
    TH1D* ScintProfile= (TH1D*)DataFile->Get(ScintProfileName.data());
    assert(ScintProfile!=NULL);
    LeadShowerProfiles.insert(std::make_pair(i,LeadProfile));
    ScintShowerProfiles.insert(std::make_pair(i,ScintProfile));
  }

}

FiveSimRun::~FiveSimRun(){std::cout<<"FiveSim Destructor Called"<<std::endl;}
  

TGraphErrors* FiveSimRun::GetStraightRes(){return StraightRes;}
TGraphErrors* FiveSimRun::GetCurvedRes(){return CurvedRes;}
TGraphErrors* FiveSimRun::GetSamplingRatio(){return SamplingRatio;}
TGraphErrors* FiveSimRun::GetScintSampling(){return ScintSampling;}
TGraphErrors* FiveSimRun::GetLeadSamping(){return LeadSampling;}
std::map<int,TH1D*> FiveSimRun::GetLeadShowerProfiles(){return LeadShowerProfiles;}
std::map<int,TH1D*> FiveSimRun::GetScintShowerProfiles(){return ScintShowerProfiles;}


