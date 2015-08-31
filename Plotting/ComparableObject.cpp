#include"ComparableObject.hpp"


ComparableObject::ComparableObject(std::string _DataFileName, std::string _Name):DataFileName(_DataFileName),Name(_Name){
  DataFile=new TFile(DataFileName.data());
  std::cout<<"Comparable object constructor called"<<std::endl;
}


ComparableObject::~ComparableObject(){
  std::cout<<"Comparable Object destructor called"<<std::endl;
  if(DataFile!=NULL){
    DataFile->Close();
  }
}

TGraphErrors* ComparableObject::GetStraightRes(Color_t _Color){
  assert(StraightRes!=NULL);
  StraightRes->SetLineColor(_Color);
  StraightRes->SetMarkerColor(_Color);
  StraightRes->GetFunction("fitstraight")->SetLineColor(_Color);
  return StraightRes;
}

TGraphErrors* ComparableObject::GetCurvedRes(Color_t _Color){
  assert(CurvedRes!=NULL);
  CurvedRes->SetLineColor(_Color);
  CurvedRes->SetMarkerColor(_Color);
  CurvedRes->GetFunction("fit1")->SetLineColor(_Color);
  return CurvedRes;
  
}

TGraphErrors* ComparableObject::GetSamplingRatio(Color_t _Color, int _MarkerStyle){
  assert(SamplingRatio!=NULL);
  SamplingRatio->SetLineColor(_Color);
  SamplingRatio->SetMarkerColor(_Color);
  SamplingRatio->SetMarkerStyle(_MarkerStyle);
  SamplingRatio->SetMarkerSize(2);
  return SamplingRatio;
}

TGraphErrors* ComparableObject::GetScintSampling(Color_t _Color, int _MarkerStyle){
  assert(ScintSampling!=NULL);
  ScintSampling->SetLineColor(_Color);
  ScintSampling->SetMarkerColor(_Color);
  ScintSampling->SetMarkerStyle(_MarkerStyle);
  ScintSampling->SetMarkerSize(2);
  return ScintSampling;
}

TGraphErrors* ComparableObject::GetLeadSamping(Color_t _Color, int _MarkerStyle){
  assert(LeadSampling!=NULL);
  LeadSampling->SetLineColor(_Color);
  LeadSampling->SetMarkerColor(_Color);
  LeadSampling->SetMarkerStyle(_MarkerStyle);
  LeadSampling->SetMarkerSize(2);
  return LeadSampling;
}

std::map<std::string,TH1D*> ComparableObject::GetLeadShowerProfiles(Color_t _Color){
  for(auto i=LeadShowerProfiles.begin();i!=LeadShowerProfiles.end();++i){
    i->second->SetLineColor(_Color);
    i->second->SetStats(kFALSE);
  }
  return LeadShowerProfiles;
}

std::map<std::string,TH1D*> ComparableObject::GetScintShowerProfiles(Color_t _Color){
  for(auto i=ScintShowerProfiles.begin();i!=ScintShowerProfiles.end();++i){
    i->second->SetLineColor(_Color);
    i->second->SetStats(kFALSE);
  }
  return ScintShowerProfiles;
}
