#ifndef COMPARABLEOBJECT_HPP
#define COMPARABLEOBJECT_HPP
#include"TFile.h"
#include"TGraphErrors.h"
#include<iostream>
#include<assert.h>

class ComparableObject {
protected:
  std::string Name;
  std::string DataFileName;
  TFile* DataFile=NULL;
  TGraphErrors* Theta0=NULL;
public:
  ComparableObject(std::string _DataFileName,std::string _Name);
  virtual ~ComparableObject();
  TGraphErrors* GetTheta0(Color_t _Color);
  std::string GetName()  {return Name;}
};

#endif
