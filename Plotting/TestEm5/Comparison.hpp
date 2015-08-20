#ifndef COMPARISON_HPP
#define COMPARISON_HPP

#include"ComparableObject.hpp"

class Comparison{
private:
  std::map<std::string,ComparableObject*> SimRuns;
  std::vector<Color_t> Colors;
  ComparableObject* BaseLine=NULL;
  TGraphErrors* Theta0Combination=NULL;
public:
  Comparison(std::string _Name);
  ~Comparison();
  void SetBaseLine(ComparableObject * _BaseLine);
  void AddSimRun(ComparableObject * _SimRun);
  void WriteTheta0();
 

};

#endif
