void exercise8() {

   
  TCanvas *c1 = new TCanvas("c1","A Simple Graph with error bars",200,10,700,500);

  c1->SetFillColor(42);
  c1->SetGrid();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);

  const Int_t n = 6;
  Float_t x[n]  = {1,2,3,4,5,6};
  Float_t y[n]  = {3.9,6.5,8.1,13.5,15.5,16};
  Float_t ex[n] = {.01,.01,.01,.01,.01,.01};
  Float_t ey[n] = {.5,.5,.5,.5,.5,.5};
  TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
  gr->SetTitle("Errors");
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->Draw("AP");

  c1->Update();
}
