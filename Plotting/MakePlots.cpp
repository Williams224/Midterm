#include"FiveSimRun.hpp"
#include"SixSimRun.hpp"
#include"Comparison.hpp"
int main(){
  std::string Testem3Dir="/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/";
  FiveSimRun* FiveLHCbOld= new FiveSimRun("/Users/Tim/PhD/Sim/MidTerm/Data/TestEm3/95/LHCbOld_Save95.root","v9.5 LHCbOldPL");
  std::string DataFilePath=Testem3Dir+"LHCbOldPL_Save.root";
  SixSimRun* LHCbOld= new SixSimRun(DataFilePath.data(),"LHCbOld");
  DataFilePath=Testem3Dir+"LHCbNew_Save.root";
  SixSimRun* LHCbNew= new SixSimRun(DataFilePath.data(),"LHCbNew");
  DataFilePath=Testem3Dir+"opt0_Save.root";
  SixSimRun* opt0= new SixSimRun(DataFilePath.data(),"opt0");
  DataFilePath=Testem3Dir+"opt1_Save.root";
  SixSimRun* opt1= new SixSimRun(DataFilePath.data(),"opt1");
  DataFilePath=Testem3Dir+"opt2_Save.root";
  SixSimRun* opt2= new SixSimRun(DataFilePath.data(),"opt2");
  DataFilePath=Testem3Dir+"opt3_Save.root";
  SixSimRun* opt3= new SixSimRun(DataFilePath.data(),"opt3");
  DataFilePath=Testem3Dir+"opt4_Save.root";
  SixSimRun* opt4= new SixSimRun(DataFilePath.data(),"opt4");
  
  Comparison *BoxComparison= new Comparison("BoxComparison");
  Comparison *LHCbComparison= new Comparison("LHCbComparison");
  Comparison *AllComparison = new Comparison("AllComparison");
  LHCbComparison->AddSimRun(LHCbOld);
  LHCbComparison->AddSimRun(LHCbNew);
  BoxComparison->AddSimRun(opt0);
  BoxComparison->AddSimRun(opt1);
  BoxComparison->AddSimRun(opt2);
  BoxComparison->AddSimRun(opt3);
  BoxComparison->AddSimRun(opt4);
  LHCbComparison->AddSimRun(FiveLHCbOld);
  
  AllComparison->AddSimRun(LHCbOld);
  AllComparison->AddSimRun(LHCbNew);
  AllComparison->AddSimRun(opt0);
  // AllComparison->AddSimRun(opt1);
  //  AllComparison->AddSimRun(opt2);
  AllComparison->AddSimRun(opt3);
  AllComparison->AddSimRun(opt4);
  AllComparison->AddSimRun(FiveLHCbOld);
  TFile* BoxOut = new TFile("BoxOutput.root","RECREATE");
  BoxComparison->WriteStraightRes();
  BoxComparison->WriteCurvedRes();
  BoxComparison->WriteSamplingRatio();
  BoxComparison->WriteScintSampling();
  BoxComparison->WriteLeadSampling();
  BoxComparison->WriteShowers();
  BoxOut->Close();
  TFile* LHCbOut = new TFile("LHCbOutput.root","RECREATE");
  LHCbComparison->WriteStraightRes();
  LHCbComparison->WriteCurvedRes();
  LHCbComparison->WriteSamplingRatio();
  LHCbComparison->WriteScintSampling();
  LHCbComparison->WriteLeadSampling();
  LHCbComparison->WriteShowers();
  LHCbOut->Close();
  TFile* AllOut= new TFile("AllOutput.root","RECREATE");
  AllComparison->WriteStraightRes();
  AllComparison->WriteCurvedRes();
  AllComparison->WriteSamplingRatio();
  AllComparison->WriteScintSampling();
  AllComparison->WriteLeadSampling();
  AllComparison->WriteShowers();
  AllOut->Close();
}
