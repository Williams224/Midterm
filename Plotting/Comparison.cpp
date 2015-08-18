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

  Energies.insert(std::make_pair(1,44.44));
  Energies.insert(std::make_pair(2,25.0));
  Energies.insert(std::make_pair(3,16.0));
  Energies.insert(std::make_pair(4,11.11));
  Energies.insert(std::make_pair(5,8.16));
  Energies.insert(std::make_pair(6,6.25));
  Energies.insert(std::make_pair(7,4.94));
  Energies.insert(std::make_pair(8,4.00));
  Energies.insert(std::make_pair(9,3.31));
  Energies.insert(std::make_pair(10,2.78));
  Energies.insert(std::make_pair(11,2.37));
  Energies.insert(std::make_pair(12,2.04));
  Energies.insert(std::make_pair(13,1.78));
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
  for(int i=1;i<=13;++i){
    TCanvas ShowerCanvas("Shower Comparisons","Shower Comparisons",1800,1000);
    TLegend ShowerLegend(0.6,0.75,0.9,0.9);
    ShowerCanvas.Divide(2,1);
    auto c= Colors.begin();
    double ScintMax=0;
    double LeadMax=0;
    TH1D* FirstLead;
    TH1D* FirstScint;
    std::string LeadTitle="Shower Profile in Lead at "+to_string_with_precision(Energies[i],2)+"GeV with 10000 Events";
    std::string ScintTitle="Shower Profile in Scintillator at "+to_string_with_precision(Energies[i],2)+"GeV with 10000 Events";
    for(auto s=SimRuns.begin();s!=SimRuns.end();++s,++c){
      Color_t CurrentColor=(*c);
      ShowerCanvas.cd(1);
      std::map<std::string, TH1D*> CurrentLeadShowers=s->second->GetLeadShowerProfiles(CurrentColor);
      TH1D* CurrentLeadShower=CurrentLeadShowers[std::to_string(i)];
      double CurrentLeadMax=CurrentLeadShower->GetBinContent(CurrentLeadShower->GetMaximumBin());
      if(CurrentLeadMax>LeadMax)LeadMax=CurrentLeadMax;
      ShowerLegend.AddEntry(CurrentLeadShower,(s->second->GetName()).data());
      if(s==SimRuns.begin()){
	CurrentLeadShower->Draw();
	CurrentLeadShower->SetTitle(LeadTitle.data());
	FirstLead=CurrentLeadShower;
      }
      else{CurrentLeadShower->Draw("SAME");}
      ShowerLegend.Draw();
      //====================RightSide==================================
      ShowerCanvas.cd(2);
      std::map<std::string,TH1D*> CurrentScintShowers=s->second->GetScintShowerProfiles(CurrentColor);
      TH1D* CurrentScintShower=CurrentScintShowers[std::to_string(i)];
      double CurrentScintMax=CurrentScintShower->GetBinContent(CurrentScintShower->GetMaximumBin());
      if(CurrentScintMax>ScintMax){ScintMax=CurrentScintMax;}
      if(s==SimRuns.begin()){
	CurrentScintShower->Draw();
	CurrentScintShower->SetTitle(ScintTitle.data());
  	FirstScint=CurrentScintShower;
      }
      else{CurrentScintShower->Draw("SAME");}
      ShowerLegend.Draw();
    }
    FirstScint->GetYaxis()->SetRangeUser(0.0,ScintMax*1.05);
    FirstLead->GetYaxis()->SetRangeUser(0.0,LeadMax*1.05);
    FirstScint->GetYaxis()->SetTitleOffset(1.3);
    FirstLead->GetYaxis()->SetTitleOffset(1.3);
    ShowerCanvas.Write();
  }

}
