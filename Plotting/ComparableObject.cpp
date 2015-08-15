#include"ComparableObject.hpp"


ComparableObject::ComparableObject(std::string _DataFileName, std::string _Name):DataFileName(_DataFileName),Name(_Name){
  DataFile=new TFile(DataFileName.data());
}


ComparableObject::~ComparableObject(){
  std::cout<<"Comparable Object destructor called"<<std::endl;
  if(DataFile!=NULL){
    DataFile->Close();
  }
  /*delete DataFile;
  delete StraightRes;
  delete CurvedRes;
  delete SamplingRatio;
  delete ScintSampling;
  delete LeadSampling;*/
}

TGraphErrors* ComparableObject::GetStraightRes(){
  assert(StraightRes!=NULL);
  return StraightRes;
}

TGraphErrors* ComparableObject::GetCurvedRes(){
  assert(CurvedRes!=NULL);
  return CurvedRes;
}

TGraphErrors* ComparableObject::GetSamplingRatio(){
  assert(SamplingRatio!=NULL);
  return SamplingRatio;
}

TGraphErrors* ComparableObject::GetScintSampling(){
  assert(ScintSampling!=NULL);
  return ScintSampling;
}

TGraphErrors* ComparableObject::GetLeadSamping(){
  assert(LeadSampling!=NULL);
  return LeadSampling;
}

std::map<int,TH1D*> ComparableObject::GetLeadShowerProfiles(){return LeadShowerProfiles;}

std::map<int,TH1D*> ComparableObject::GetScintShowerProfiles(){return ScintShowerProfiles;}
