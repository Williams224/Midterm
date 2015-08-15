#ifndef COMPARABLEOBJECT_HPP
#define COMPARABLEOBJECT_HPP
#include"TFile.h"
#include"TGraphErrors.h"
#include<map>
#include<string>
#include"TH1D.h"
#include<iostream>
#include<assert.h>

class ComparableObject{
protected:
  std::string Name;
  std::string DataFileName;
  TFile* DataFile=NULL;
  TGraphErrors* StraightRes=NULL;
  TGraphErrors* CurvedRes=NULL;
  std::map<int,TH1D*> LeadShowerProfiles;
  std::map<int,TH1D*> ScintShowerProfiles;
  TGraphErrors* SamplingRatio=NULL;
  TGraphErrors* ScintSampling=NULL;
  TGraphErrors* LeadSampling=NULL;
  public:
  ComparableObject(std::string _DataFileName,std::string _Name);
  virtual ~ComparableObject();
  std::string GetName(){return Name;}
  virtual TGraphErrors* GetStraightRes();
  virtual TGraphErrors* GetCurvedRes();
  virtual TGraphErrors* GetSamplingRatio();
  virtual TGraphErrors* GetScintSampling();
  virtual TGraphErrors* GetLeadSamping();
  virtual std::map<int,TH1D*> GetLeadShowerProfiles();
  virtual std::map<int,TH1D*> GetScintShowerProfiles();
 
};

#endif

