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

Comparison::SetBaseLine(ComparableObject * _BaseLine){
  assert(_BaseLine!=NULL);
  BaseLine=_BaseLine;
}

Comparison::AddSimRun(ComparableObject* _SimRun){
  assert(_SimRun!=NULL);
  SimRuns.insert(std::make_pair(_SimRun->GetName(),_SimRun));
}

Comparison::WriteTheta0(){
  assert(SimRuns.size()>=1);
  



}
