#include"ComparableObject.hpp"

ComparableObject::ComparableObject(std::string _DataFileName, std::string _Name):DataFileName(_DataFileName),Name(_Name){
  DataFile=new TFile(DataFileName.data());
  Theta0=(TGraphErrors*)DataFile->Get("Graph;1");
  assert(Theta0!=NULL);
  std::cout<<"Comparable object constructor called"<<std::endl;
}

ComparableObject::~ComparableObject(){
  std::cout<<"Comparable Object destructor called"<<std::endl;
  if(DataFile!=NULL){
    DataFile->Close();
  }
}

TGraphErrors* ComparableObject::GetTheta0(Color_t _Color){
  Theta0->SetMarkerColor(_Color);
  Theta0->SetLineColor(_Color);
  return Theta0;
}

