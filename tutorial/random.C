#include "TCanvas.h"
#include <TRandom.h>

void random() {
    
  TCanvas *c1 = new TCanvas("c1","demo",200,10,700,500);
  c1->SetFillColor(42);

  TRandom r;
  gRandom->SetSeed();
    
  TH1F *histo1 = new TH1F("histo1","s",100,0.,1.);
  histo1->SetMarkerStyle(21);
  int n;
  cin >> n;
  for (int i=0;i<n;i++) {
    float p1=r.Uniform(0,1);
    histo1->Fill(p1);
  }
  
  histo1->Fit("gaus");
  histo1->Draw("");
  c1->SaveAs("c1.gif");
}
