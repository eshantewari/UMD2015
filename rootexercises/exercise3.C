#include "TCanvas.h"
#include "TEllipse.h"

void exercise3(){
  TCanvas *c1 = new TCanvas("c1");
  c1->Range(0,0,.6,.6);


  TEllipse *el1 = new TEllipse(0.15,0.3,.1,.1);
  el1->Draw();
  TEllipse *el2 = new TEllipse(0.23,0.15,.1,.1);
  el2->Draw();
  TEllipse *el3 = new TEllipse(0.31,0.3,.1,.1);
  el3->Draw();
  TEllipse *el4 = new TEllipse(0.39,0.15,.1,.1);
  el4->Draw();
  TEllipse *el5 = new TEllipse(0.47,0.3,.1,.1);
  el5->Draw();
  c1->SaveAs("c1.gif");
}
