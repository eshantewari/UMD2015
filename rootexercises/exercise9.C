void exercise9(){

  TCanvas *c1 = new TCanvas("c1", "Line of best fit", 200, 10, 700, 500);
  c1->SetFillColor(42);
  c1->SetGrid();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);

  const Int_t n = 5;
  Float_t x[n] = {10, 20, 30, 40, 50};
  Float_t y[n] = {.9,1.4,2.2,2.2,3.3};
  Float_t ex[n] = {0,0,0,0,0};
  Float_t ey[n] = {.2,.2,.2,.2,.2};
  TGraphErrors *gr = new TGraphErrors(n, x, y, ex, ey);
  gr->SetTitle("Line of Best Fit");
  gr->SetMarkerStyle(4);
  gr->SetMarkerStyle(21);
  gr->Fit("pol1");
  gr->Draw("AP");

}
