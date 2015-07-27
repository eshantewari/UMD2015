void compare() {

  // Create TCanvas
  TCanvas* c1 = new TCanvas("c1");
  c1->SetLogy(1);

  // Open files to compare
  TFile* dataRootFile = TFile::Open("Dielectron_Data_nocuts.root");
  TFile* mcRootFile = TFile::Open("Dielectron_MC_nocuts.root");
  
  // Find histograms named h_ee in each file
  TH1F* h_ee_data = (TH1F*)dataRootFile->Get("Z_ee");
  TH1F* h_ee_mc   = (TH1F*)mcRootFile  ->Get("Z_ee");
  
  // Make histograms look different for comparison purposes
  h_ee_mc->SetLineColor(kBlue);
  h_ee_mc->SetLineWidth(2);
  h_ee_data->SetLineColor(kBlack);
  h_ee_data->SetLineWidth(2);

  h_ee_mc  ->DrawNormalized("");
  h_ee_data->DrawNormalized("SAMES");

  // Do not forget to label things
  TLegend* leg = new TLegend(0.6, 0.7, 0.75, 0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(h_ee_mc, "MC", "l");
  leg->AddEntry(h_ee_data, "Data", "l");
  leg->Draw();
}