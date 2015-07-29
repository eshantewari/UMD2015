#include "TMath.h"

void exercise6(){
   
TCanvas *c1 = new TCanvas("c1","Sum of Sin Waves",200,10,700,900);
c1->SetFillColor(18);

pad1 = new TPad("pad1","Function",0.05,0.50,0.95,0.95,21);
pad1->Draw();
pad1->cd();

gBenchmark->Start("exercise6");
//
// A function (any dimension) or a formula may reference
// an already defined formula
//
form1 = new TFormula("Sum","sin(x*50*pow(10,6)*2*TMath::Pi())+sin(x*55*pow(10,6)*2*TMath::Pi())");
sum = new TF1("sum","Sum",0,1);
sum->SetParameters(10,4,1,20);
pad1->SetGridx();
pad1->SetGridy();
pad1->GetFrame()->SetFillColor(42);
pad1->GetFrame()->SetBorderMode(-1);
pad1->GetFrame()->SetBorderSize(5);
sum->SetLineColor(4);
sum->SetLineWidth(6);
sum->Draw();
c1->Update();
}
