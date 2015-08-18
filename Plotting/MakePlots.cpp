#include"FiveSimRun.hpp"
#include"SixSimRun.hpp"
#include"Comparison.hpp"
int main(){
  FiveSimRun* FiveOpt1= new FiveSimRun("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/95/LHCbOld_Save95.root","v9.5 LHCb Private PL");
  SixSimRun* SixOpt1= new SixSimRun("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/LHCbNew_Save.root","v9.6 LHCb Private PL");
  Comparison *TheComparison= new Comparison("StraightComparison");
  TheComparison->AddSimRun(SixOpt1);
  TheComparison->AddSimRun(FiveOpt1);
  TFile* Out = new TFile("Output.root","RECREATE");
  TheComparison->WriteStraightRes();
  TheComparison->WriteCurvedRes();
  TheComparison->WriteSamplingRatio();
  TheComparison->WriteScintSampling();
  TheComparison->WriteLeadSampling();
  TheComparison->WriteShowers();
}
