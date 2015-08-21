#ifndef COMPARISON_HPP
#define COMPARISON_HPP

#include"ComparableObject.hpp"
#include<map>
#include"FillableGraph.hpp"

struct DataPoint{
  double X;
  double Y;
  double EX;
  double EY;
}
  
class Comparison{
private:
  std::string ComparisonName;
  std::map<int,double> Energies;
  std::map<std::string,ComparableObject*> SimRuns;
  std::vector<Color_t> Colors;
  std::vector<DataPoint> BaseDataPoints;
  std::vector<FillableGraph*> NormedGraphs;
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
