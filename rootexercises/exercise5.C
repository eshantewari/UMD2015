#include "TCanvas.h"


void exercise5()
{
  TF1 *fa1 = new TF1("fa1","x^2",0,5);
  fa1->Draw();
}
