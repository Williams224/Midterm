#ifndef COMPARISON_HPP
#define COMPARISON_HPP
#include"FiveSimRun.hpp"
#include"SixSimRun.hpp"
#include"TMultiGraph.h"
#include"TLegend.h"
#include"TLatex.h"
#include"TText.h"
#include"TCanvas.h"
class Comparison{
private:
  std::string ComparisonName;
  std::map<std::string,ComparableObject*> SimRuns;
  std::vector<Color_t> Colors;
  //==============================STRAIGHT==============================
  TCanvas* StraightCanvas=NULL;
  TMultiGraph* StraightMG=NULL;
  TLegend* StraightLeg=NULL;
  std::string StraightTitle;
  TLatex* StraightText;
  TText* StraightCurved;
  bool FitResultText;
  TLatex* FitEquation;
  TText* FR95;
  TText* FR96;
  // ==============================CURVED==============================
  TCanvas* CurvedCanvas=NULL;
  TMultiGraph* CurvedMG=NULL;
  TLegend* CurvedLeg=NULL;
  std::string CurvedTitle;
  
  TMultiGraph* SamplingRatioMG=NULL;
  TMultiGraph* ScintSamplingMG=NULL;
  TMultiGraph* LeadSamplingMG=NULL;

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
