#ifndef COMPARISON_HPP
#define COMPARISON_HPP
#include"FiveSimRun.hpp"
#include"SixSimRun.hpp"
#include"TMultiGraph.h"
#include"TLegend.h"
#include"TLatex.h"
#include"TText.h"
#include"TCanvas.h"
#include <sstream>
#include<iomanip>

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out << std::setprecision(n) << std::fixed<<a_value;
    return out.str();
}

class Comparison{
private:
  std::map<int,double> Energies;
  std::string ComparisonName;
  std::map<std::string,ComparableObject*> SimRuns;
  std::vector<Color_t> Colors;
  std::vector<int> Markers;
  //==============================STRAIGHT==============================
  TCanvas* StraightCanvas=NULL;
  TMultiGraph* StraightMG=NULL;
  TLegend* StraightLeg=NULL;
  std::string StraightTitle;
  TLatex* L3;
  TText* T3;
  bool FitResultText;
  TLatex* FitEquation;
  TText* FR;
  // ==============================CURVED==============================
  TCanvas* CurvedCanvas=NULL;
  TMultiGraph* CurvedMG=NULL;
  TLegend* CurvedLeg=NULL;
  std::string CurvedTitle;
  //==============================SAMPLING RATIO=======================
  TCanvas* RatioCanvas=NULL;
  TMultiGraph* SamplingRatioMG=NULL;
  TLegend* SamplingRatioLeg=NULL;
  std::string SamplingTitle;
  //==============================Scint Sampling=====================
  TCanvas* ScintSamplingCanvas=NULL;
  TMultiGraph* ScintSamplingMG=NULL;
  TLegend* ScintSamplingLeg=NULL;
  std::string ScintSamplingTitle;
  //==============================Lead Sampling========================
  TCanvas* LeadSamplingCanvas=NULL;
  TMultiGraph*LeadSamplingMG=NULL;
  TLegend* LeadSamplingLeg=NULL;
  std::string LeadSamplingTitle;
  //==============================Shower Profiles=========================
  
  

public:
  Comparison(std::string _Name);
  ~Comparison();
  bool AddSimRun(ComparableObject* _SimRun);
  void WriteStraightRes();
  void WriteCurvedRes();
  void WriteSamplingRatio();
  void WriteScintSampling();
  void WriteLeadSampling();
  void WriteShowers();
  void WriteAll();
};




#endif
