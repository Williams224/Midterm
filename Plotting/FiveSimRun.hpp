#ifndef FIVESIMRUN_HPP
#define FIVESIMRUN_HPP
#include"ComparableObject.hpp"
#include"TF1.h"

class FiveSimRun : public ComparableObject{

public:
  FiveSimRun(std::string _DataFileName,std::string _Name);
  ~FiveSimRun();
  std::map<std::string,TH1D*> GetScintShowerProfiles();
  std::map<std::string,TH1D*> GetLeadShowerProfiles();
  void WriteAll();

};


#endif
