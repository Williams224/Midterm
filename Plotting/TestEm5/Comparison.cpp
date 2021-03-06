#include"Comparison.hpp"

Comparison::Comparison(std::string _Name):ComparisonName(_Name){
  Colors.push_back(kRed);
  Colors.push_back(kBlue);
  Colors.push_back(kGreen);
  Colors.push_back(kMagenta);
  Colors.push_back(kOrange);
  Colors.push_back(kCyan+1);
  Colors.push_back(kOrange+4);
  Colors.push_back(kGreen+3);
  Colors.push_back(kYellow+3);

  Energies.insert(std::make_pair(1,1.0));
  Energies.insert(std::make_pair(2,2.0));
  Energies.insert(std::make_pair(3,3.0));
  Energies.insert(std::make_pair(4,4.0));
  Energies.insert(std::make_pair(5,5.0));
  Energies.insert(std::make_pair(6,7.0));
  Energies.insert(std::make_pair(7,9.0));
  Energies.insert(std::make_pair(8,12.0));
  Energies.insert(std::make_pair(9,15.0));
  Energies.insert(std::make_pair(10,20.0));
  Energies.insert(std::make_pair(11,25.0));
  Energies.insert(std::make_pair(12,30.0));
  Energies.insert(std::make_pair(13,40.0));

  Theta0Combination= new TMultiGraph("Theta0 Comparison","Theta0 Comparison");
  Leg=new TLegend(0.1,0.7,0.48,0.9);
}


Comparison::~Comparison(){
  delete BaseLine;
  delete Theta0Combination;
  std::cout<<"Comparison Destructor Called"<<std::endl;
}

void Comparison::SetBaseLine(ComparableObject * _BaseLine){
  assert(_BaseLine!=NULL);
  BaseLine=_BaseLine;
  TGraphErrors* BaseGr=BaseLine->GetTheta0(kRed);
  Int_t N=BaseGr->GetN();
  Double_t* BX=BaseGr->GetX();
  Double_t* BY=BaseGr->GetY();
  Double_t* BEX=BaseGr->GetEX();
  Double_t* BEY=BaseGr->GetEY();
  for(int i=0;i<N;++i){
    DataPoint Tmp;
    Tmp.X=BX[i];
    Tmp.Y=BY[i];
    Tmp.EX=BEX[i];
    Tmp.EY=BEY[i];
    BaseDataPoints.push_back(Tmp);
  }
}

void Comparison::AddSimRun(ComparableObject* _SimRun){
  assert(_SimRun!=NULL);
  SimRuns.insert(std::make_pair(_SimRun->GetName(),_SimRun));
}

void Comparison::WriteTheta0(){
  assert(SimRuns.size()>=1);
  auto c=Colors.begin();
  for(auto s =SimRuns.begin();s!=SimRuns.end();++s,++c){
    TGraphErrors* Gr=s->second->GetTheta0((*c));
    Int_t N=Gr->GetN();
    assert(N==BaseDataPoints.size());
    Double_t* X=Gr->GetX();
    Double_t* Y=Gr->GetY();
    Double_t* EX=Gr->GetEX();
    Double_t* EY=Gr->GetEY();
    std::string NormedName=s->second->GetName();
    std::cout<<"NormedName= "<<NormedName<<std::endl;
    FillableGraph* NormedGr=new FillableGraph(NormedName.data());
    //    NormedGr->SetMarkerStyle(5);
    NormedGraphs.push_back(NormedGr);
    for(int i=0;i<N;++i){
      double fX=X[i];
      double fY=Y[i]/BaseDataPoints.at(i).Y;
      double fEX=0;
      double A=EY[i]/BaseDataPoints.at(i).Y;
      double B=(Y[i]*BaseDataPoints.at(i).EY)/(BaseDataPoints.at(i).Y*BaseDataPoints.at(i).Y);
      double fEY=TMath::Sqrt(std::pow(A,2)+std::pow(B,2));
      // std::cout<<"Y= "<<Y[i]<<" +/- "<<EY[i]<<std::endl;
      // std::cout<<"Base Y= "<<BaseDataPoints.at(i).Y<<" +/- "<<BaseDataPoints.at(i).EY<<std::endl;
      // std::cout<<"fY= "<<fY<<" +/- "<<fEY<<std::endl;
      std::cout<<"Energy= "<<fX<<" Sigma= "<<((fY-1)/fEY)<<std::endl;
      std::cout<<"Energy= "<<fX<<" Percent= "<<(fY-1)<<std::endl;
      NormedGr->Fill(fX,fY,fEX,fEY);
     
    }
    TGraphErrors* tmp=NormedGr->ColoredData(*c);
    tmp->SetMarkerStyle(5);
    Theta0Combination->Add(NormedGr->ColoredData(*c),"AP");
    Leg->AddEntry(NormedGr->ColoredData(*c),(s->second->GetName()).data(),"lep");
     std::cout<<"Got Here"<<std::endl;
  }
  TCanvas C(ComparisonName.data(),ComparisonName.data(),1800,1000);
  Theta0Combination->Draw("AP");
  Leg->Draw();
  C.Write();
}
