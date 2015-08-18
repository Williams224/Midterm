#include"FiveSimRun.hpp"
#include"SixSimRun.hpp"
#include"Comparison.hpp"
int main(){
  std::string Testem3Dir="/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/";
  FiveSimRun* FiveLHCbOld= new FiveSimRun("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/95/LHCbOld_Save95.root","v9.5 LHCbOld PL");
  std::string DataFilePath=Testem3Dir+"LHCbOldPL_Save.root";
  SixSimRun* LHCbOld= new SixSimRun(DataFilePath.data(),"LHCbOld");
  DataFilePath=Testem3Dir+"LHCbNew_Save.root";
  SixSimRun* LHCbNew= new SixSimRun(DataFilePath.data(),"LHCbNew");
  DataFilePath=Testem3Dir+"opt1_Save.root";
  SixSimRun* opt1= new SixSimRun(DataFilePath.data(),"opt1");
  DataFilePath=Testem3Dir+"opt2_Save.root";
  SixSimRun* opt2= new SixSimRun(DataFilePath.data(),"opt2");
  DataFilePath=Testem3Dir+"opt3_Save.root";
  SixSimRun* opt3= new SixSimRun(DataFilePath.data(),"opt3");
  DataFilePath=Testem3Dir+"opt4_Save.root";
  SixSimRun* opt4= new SixSimRun(DataFilePath.data(),"opt4");
  
  Comparison *TheComparison= new Comparison("StraightComparison");
  TheComparison->AddSimRun(LHCbOld);
  TheComparison->AddSimRun(LHCbNew);
  TheComparison->AddSimRun(opt1);
  TheComparison->AddSimRun(opt2);
  TheComparison->AddSimRun(opt3);
  TheComparison->AddSimRun(opt4);
  //  TheComparison->AddSimRun(FiveOpt1);
  TFile* Out = new TFile("Output.root","RECREATE");
  TheComparison->WriteStraightRes();
  TheComparison->WriteCurvedRes();
  TheComparison->WriteSamplingRatio();
  TheComparison->WriteScintSampling();
  TheComparison->WriteLeadSampling();
  TheComparison->WriteShowers();
}
