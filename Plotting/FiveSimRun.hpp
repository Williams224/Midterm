#ifndef FIVESIMRUN_HPP
#define FIVESIMRUN_HPP
#include"ComparableObject.hpp"

class FiveSimRun : public ComparableObject{

public:
  FiveSimRun(std::string _DataFileName,std::string _Name);
  ~FiveSimRun();
  TGraphErrors* GetStraightRes();
  TGraphErrors* GetCurvedRes();
  TGraphErrors* GetSamplingRatio();
  TGraphErrors* GetScintSampling();
  TGraphErrors* GetLeadSamping();
  std::map<int,TH1D*> GetScintShowerProfiles();
  std::map<int,TH1D*> GetLeadShowerProfiles();
  

};


#endif
