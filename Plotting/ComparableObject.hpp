#ifndef COMPARABLEOBJECT_HPP
#define COMPARABLEOBJECT_HPP
#include"TFile.h"
#include"TGraphErrors.h"
#include<map>
#include<string>
#include"TH1D.h"
#include<iostream>
#include<assert.h>
#include"TF1.h"

class ComparableObject{
protected:
  std::string Name;
  std::string DataFileName;
  TFile* DataFile=NULL;
  TGraphErrors* StraightRes=NULL;
  TGraphErrors* CurvedRes=NULL;
  std::map<std::string,TH1D*> LeadShowerProfiles;
  std::map<std::string,TH1D*> ScintShowerProfiles;
  TGraphErrors* SamplingRatio=NULL;
  TGraphErrors* ScintSampling=NULL;
  TGraphErrors* LeadSampling=NULL;
  public:
  ComparableObject(std::string _DataFileName,std::string _Name);
  virtual ~ComparableObject();
  std::string GetName(){return Name;}
  virtual TGraphErrors* GetStraightRes(Color_t _Color);
  virtual TGraphErrors* GetCurvedRes(Color_t _Color);
  virtual TGraphErrors* GetSamplingRatio(Color_t _Color);
  virtual TGraphErrors* GetScintSampling(Color_t _Color);
  virtual TGraphErrors* GetLeadSamping(Color_t _Color);
  virtual std::map<std::string,TH1D*> GetLeadShowerProfiles(Color_t _Color);
  virtual std::map<std::string,TH1D*> GetScintShowerProfiles();
 
};

#endif

