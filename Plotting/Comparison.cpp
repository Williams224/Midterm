#include"Comparison.hpp"

Comparison::Comparison(std::string _Name):ComparisonName(_Name){
  Colors.push_back(kRed);
  Colors.push_back(kBlue);
  Colors.push_back(kGreen+2);
  Colors.push_back(kMagenta);
  Colors.push_back(kOrange);
  FitEquation= new TLatex();
  FitEquation->SetTextSize(0.03);

  FR= new TText();
  FR->SetTextSize(0.03);
  T3= new TText();
  T3->SetTextSize(0.03);
  T3->SetTextSize(0.03);
  L3= new TLatex();
  L3->SetTextSize(0.03);
  
}

Comparison::~Comparison(){
  delete StraightCanvas;
  delete StraightMG;
  delete StraightLeg;
  delete L3;
  delete T3;
  delete FitEquation;
  delete FR;
  delete RatioCanvas;
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
  StraightLeg->Draw();
  if(SimRuns.size()==2)FR->DrawText(0.13,0.07,"v9.5 Fit Result");
  if(SimRuns.size()==2)FR->DrawText(0.18,0.07,"v9.6 Fit Result");
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
  StraightLeg->Draw();
  if(SimRuns.size()==2)FR->DrawText(0.13,0.07,"v9.5 Fit Result");
  if(SimRuns.size()==2)FR->DrawText(0.18,0.07,"v9.6 Fit Result");
  CurvedCanvas->Write();
}

void Comparison::WriteSamplingRatio(){
  RatioCanvas=new TCanvas("Sampling Ration Comparison","Sampling Ratio Comparison",1800,1000);
  SamplingRatioMG=new TMultiGraph();
  SamplingRatioLeg=new TLegend(0.1,0.75,0.48,0.9);
  auto c=Colors.begin();
  assert(Colors.size()>=SimRuns.size());
  SamplingTitle="Comparison of ";
  for(auto s=SimRuns.begin();s!=SimRuns.end();++s,++c){
    Color_t CurrentColor=(*c);
    SamplingRatioMG->Add(s->second->GetSamplingRatio(CurrentColor));
    SamplingRatioLeg->AddEntry(s->second->GetSamplingRatio(CurrentColor),(s->second->GetName()).data(),"LPE");
    SamplingTitle=SamplingTitle+(s->second->GetName())+", ";
  }
  SamplingRatioMG->Draw("AP");
  SamplingRatioMG->SetTitle(SamplingTitle.data());
  SamplingRatioMG->GetYaxis()->SetTitle("Scintillator E/Lead E");
  SamplingRatioMG->GetXaxis()->SetTitle("Incident Energy/GeV");
  SamplingRatioLeg->Draw();
  RatioCanvas->Write();
}

void Comparison::WriteScintSampling(){
  ScintSamplingCanvas=new TCanvas("Scintillator Sampling Fraction","Scintillator Sampling Fraction",1800,1000);
  ScintSamplingMG= new TMultiGraph();
  ScintSamplingLeg= new TLegend(0.1,0.75,0.48,0.9);
  auto c=Colors.begin();
  assert(Colors.size()>=SimRuns.size());
  ScintSamplingTitle="Comparison of ";
  for(auto s=SimRuns.begin();s!=SimRuns.end();++s,++c){
    Color_t CurrentColor=(*c);
    ScintSamplingMG->Add(s->second->GetScintSampling(CurrentColor));
    ScintSamplingLeg->AddEntry(s->second->GetScintSampling(CurrentColor),(s->second->GetName()).data(),"LPE");
    ScintSamplingTitle=ScintSamplingTitle+(s->second->GetName())+", ";
  }
  ScintSamplingTitle=ScintSamplingTitle+" with 10000 events";
  ScintSamplingMG->Draw("AP");
  ScintSamplingLeg->Draw();
  ScintSamplingMG->SetTitle(ScintSamplingTitle.data());
  ScintSamplingMG->GetYaxis()->SetTitle("Scintillator E/Incident E");
  ScintSamplingMG->GetYaxis()->SetTitleOffset(1.3);
  ScintSamplingMG->GetXaxis()->SetTitle("Incident Energy/GeV");
  ScintSamplingCanvas->Write();
}

void Comparison::WriteLeadSampling(){
  LeadSamplingCanvas=new TCanvas("Lead Sampling Fraction","Lead Sampling Fraction",1800,1000);
  LeadSamplingMG= new TMultiGraph();
  LeadSamplingLeg= new TLegend(0.1,0.75,0.48,0.9);
  auto c=Colors.begin();
  assert(Colors.size()>=SimRuns.size());
  LeadSamplingTitle="Comparison of ";
  for(auto s=SimRuns.begin();s!=SimRuns.end();++s,++c){
    Color_t CurrentColor=(*c);
    LeadSamplingMG->Add(s->second->GetLeadSamping(CurrentColor));
    LeadSamplingLeg->AddEntry(s->second->GetLeadSamping(CurrentColor),(s->second->GetName()).data(),"LPE");
    LeadSamplingTitle=LeadSamplingTitle+(s->second->GetName())+", ";
  }
  LeadSamplingTitle=LeadSamplingTitle+" with 10000 events";
  LeadSamplingMG->Draw("AP");
  LeadSamplingLeg->Draw();
  LeadSamplingMG->SetTitle(LeadSamplingTitle.data());
  LeadSamplingMG->GetYaxis()->SetTitle("Leadillator E/Incident E");
  LeadSamplingMG->GetYaxis()->SetTitleOffset(1.3);
  LeadSamplingMG->GetXaxis()->SetTitle("Incident Energy/GeV");
  LeadSamplingCanvas->Write();
}

void Comparison::WriteShowers(){
  for(i=1;i<=13;++i){
    TCanvas ShowerCanvas("Shower Comparisons","Shower Comparisons",1800,1000);
    ShowerCanvas.Divide(2,1);
    ShowerCanvas.cd(1);
    auto c= Colors.begin();
    for(auto s=SimRuns.being();s!=SimRuns.end();++s,++c){
      Color_t CurrentColor=c->second;
      (s->second->GetLeadShowerProfiles(CurrentColor))->second

    }

  }



}
