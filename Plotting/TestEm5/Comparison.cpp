#include"Comparison.hpp"

Comparison::Comparison(std::string _Name):ComparisonName(_Name){
  Colors.push_back(kRed);
  Colors.push_back(kBlue);
  Colors.push_back(kGreen);
  Colors.push_back(kMagenta);
  Colors.push_back(kOrange);
  Colors.push_back(kCyan+1);
  Colors.push_back(kOrange+4);
  Colors.push_back(kGreen+3);
  Colors.push_back(kYellow+3);

  Energies.insert(std::make_pair(1,1.0));
  Energies.insert(std::make_pair(2,2.0));
  Energies.insert(std::make_pair(3,3.0));
  Energies.insert(std::make_pair(4,4.0));
  Energies.insert(std::make_pair(5,5.0));
  Energies.insert(std::make_pair(6,7.0));
  Energies.insert(std::make_pair(7,9.0));
  Energies.insert(std::make_pair(8,12.0));
  Energies.insert(std::make_pair(9,15.0));
  Energies.insert(std::make_pair(10,20.0));
  Energies.insert(std::make_pair(11,25.0));
  Energies.insert(std::make_pair(12,30.0));
  Energies.insert(std::make_pair(13,40.0));
}


Comparison::~Comparison(){
  delete BaseLine;
  delete Theta0Combination;
  std::cout<<"Comparison Destructor Called"<<std::endl;
}

void Comparison::SetBaseLine(ComparableObject * _BaseLine){
  assert(_BaseLine!=NULL);
  BaseLine=_BaseLine;
  TGraphErrors* BaseGr=BaseLine->GetTheta0(kRed);
  Int_t N=BaseGr->GetN();
  Double_t* BX=BaseGr->GetX();
  Double_t* BY=BaseGr->GetY();
  Double_t* BEX=BaseGr->GetEX();
  Double_t* BEY=BaseGr->GetEY();
  for(int i=0;i<N;++i){
    DataPoint Tmp;
    Tmp.X=BX[i];
    Tmp.Y=BY[i];
    Tmp.EX=BEX[i];
    Tmp.EY=BEY[i];
    BaseDataPoints.push_back(Tmp);
  }
}

void Comparison::AddSimRun(ComparableObject* _SimRun){
  assert(_SimRun!=NULL);
  SimRuns.insert(std::make_pair(_SimRun->GetName(),_SimRun));
}

void Comparison::WriteTheta0(){
  assert(SimRuns.size()>=1);
  auto c=Colors.begin();
  for(auto s =SimRuns.begin();s!=SimRuns.end();++s,++c){
    TGraphErrors* Gr=s->second->GetTheta0((*c));
    Int_t N=Gr->GetN();
    assert(N==BaseDataPoints.size());
    Double_t* X=Gr->GetX();
    Double_t* Y=Gr->GetY();
    Double_t* EX=Gr->GetEX();
    Double_t* EY=Gr->GetEY();
  }
  
  


}
