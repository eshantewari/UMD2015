#include "TCanvas.h"
#include <TRandom.h>

void exercise1() {
    
  TCanvas *c1 = new TCanvas("c1","Poisson Distribution",200,10,700,500);
  c1->SetFillColor(42);

  TRandom r;
  gRandom->SetSeed();
    
  TH1F *histo1 = new TH1F("histo1","s",50,0.,30.);
  histo1->SetMarkerStyle(21);
  for (int i=0;i<500;i++) {
    float p1=r.Poisson(2.3);
    histo1->Fill(p1);
  }
  histo1->Draw("");
  c1->SaveAs("c1.gif");
}
