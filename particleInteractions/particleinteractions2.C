#include "TCanvas.h"

double mass = 105.6583715; //MeV/c^2
double c = 1;
double lifetime = 2.1969811*pow(10,-6); //s
double length = 1;

void particleinteractions2() {
  //Draw a simple graph
  // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
  //Author: Rene Brun

  TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

  c1->SetFillColor(42);
  c1->SetGrid();

  const Int_t n = 1000;
  Double_t x[n], y[n];
  int minEnergy = ceil(mass*pow(c,2));
  for (Int_t i=0; i < 1000;i++) {
    double  energy = minEnergy+i;
    x[i] = energy;
    y[i] = exp(-mass*c/(lifetime*sqrt(energy*energy-mass*mass*pow(c, 4))));
    printf(" i %i %f %f \n",i,x[i],y[i]);
  }
  TGraph *gr = new TGraph(n,x,y);
  gr->SetLineColor(2);
  gr->SetLineWidth(4);
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->SetTitle("Particle Decay Graph");
  gr->GetXaxis()->SetTitle("Energy (MeV)");
  gr->GetYaxis()->SetTitle("Probability");
  gr->Draw("ACP");

  // TCanvas::Update() draws the frame, after which one can change it
  c1->Update();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
}
