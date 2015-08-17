#include"Comparison.hpp"

Comparison::Comparison(std::string _Name):ComparisonName(_Name){
  Colors.push_back(kRed);
  Colors.push_back(kBlue);
  Colors.push_back(kGreen+2);
  Colors.push_back(kMagenta);
  Colors.push_back(kOrange);
}

Comparison::~Comparison(){
  delete StraightCanvas;
  delete StraightMG;
  delete StraightLeg;
  delete StraightText;
  delete StraightCurved;
  delete FitEquation;
  delete FR95;
  delete FR96;
  std::cout<<"Comparison Destructor Called"<<std::endl;
}

bool Comparison::AddSimRun(ComparableObject* _SimRun){
  assert(_SimRun!=NULL);
  SimRuns.insert(std::make_pair(_SimRun->GetName(),_SimRun));
}

void Comparison::WriteStraightRes(){
  StraightCanvas= new TCanvas("Straight Resolution Comparison","Straight Resolution Comparison",1800,1000);
  StraightMG = new TMultiGraph();
  StraightLeg= new TLegend(0.1,0.75,0.48,0.9);
  StraightTitle="Comparison of ";
  auto c=Colors.begin();
  assert(Colors.size()>=SimRuns.size());
  for(auto s=SimRuns.begin();s!=SimRuns.end();++s,++c){
    Color_t CurrentColor=(*c);
    StraightMG->Add(s->second->GetStraightRes(CurrentColor));
    StraightLeg->AddEntry(s->second->GetStraightRes(CurrentColor),(s->second->GetName()).data(),"LPE");
    StraightTitle=StraightTitle+(s->second->GetName())+", ";
  }
  StraightTitle=StraightTitle+"with 10000 events";
  StraightMG->Draw("AP");
  StraightMG->SetTitle(StraightTitle.data());
  StraightMG->GetYaxis()->SetTitle("#frac{#sigma}{E}");
  StraightMG->GetXaxis()->SetTitle("#frac{1}{#sqrt{E_{i}}}");
  StraightText= new TLatex();
  StraightText->SetTextSize(0.03);
  StraightText->DrawLatex(0.13,0.059,"#sigma=Resolution of Energy Distribution in Active Layers");
  StraightCurved= new TText();
  StraightCurved->SetTextSize(0.03);
  StraightCurved->SetTextSize(0.03);
  StraightCurved->DrawText(0.13,0.055,"E= Total Energy Deposited in Active Layers");

  FitEquation= new TLatex();
  FitEquation->DrawLatex(0.13,0.051,"Fit: #frac{#sigma}{E}=#frac{a}{#sqrt{E}} #oplus C");
  FitEquation->SetTextSize(0.03);
  StraightLeg->Draw();

  FR95= new TText();
  FR95->SetTextSize(0.03);
  FR95->SetTextSize(0.03);
  if(SimRuns.size()==2)FR95->DrawText(0.13,0.07,"v9.5 Fit Result");

  FR96= new TText();
  FR95->SetTextSize(0.03);
  FR95->SetTextSize(0.03);
  if(SimRuns.size()==2)FR95->DrawText(0.18,0.07,"v9.6 Fit Result");
  StraightCanvas->Write();
    

}

void Comparison::WriteCurvedRes(){
  CurvedCanvas=new TCanvas("Curved Resolution Comparison","Curved Resolution Comparison",1800,1000);
  CurvedMG=new TMultiGraph();
  CurvedLeg=new TLegend(0.1,0.75,0.48,0.9);
  CurvedTitle="Comparison of ";
  auto c=Colors.begin();
  assert(Colors.size()>=SimRuns.size());
  for(auto s=SimRuns.begin();s!=SimRuns.end();++s,++c){
    Color_t CurrentColor=(*c);
    CurvedMG->Add(s->second->GetCurvedRes(CurrentColor));
    CurvedLeg->AddEntry(s->second->GetCurvedRes(CurrentColor),(s->second->GetName()).data(),"LPE");
    CurvedTitle=CurvedTitle+(s->second->GetName())+", ";
  }
  CurvedTitle=CurvedTitle+"with 10000 events";
  CurvedMG->Draw("AP");
  CurvedMG->SetTitle(CurvedTitle.data());
  CurvedMG->GetYaxis()->SetTitle("#frac{#sigma}{E}");
  CurvedMG->GetXaxis()->SetTitle("#frac{1}{#sqrt{E_{i}}}");
  CurvedCanvas->Write();
  FitEquation


}
