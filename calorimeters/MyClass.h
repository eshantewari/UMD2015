//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 14 12:38:40 2015 by ROOT version 5.32/00
// from TTree t1/a tree
// found on file: output.root
//////////////////////////////////////////////////////////

#ifndef MyClass_h
#define MyClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class MyClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         e1;
   Float_t         px1;
   Float_t         py1;
   Float_t         pz1;
   Float_t         e2;
   Float_t         px2;
   Float_t         py2;
   Float_t         pz2;
   Float_t         eb1;
   Float_t         pxb1;
   Float_t         pyb1;
   Float_t         pzb1;
   Float_t         eb2;
   Float_t         pxb2;
   Float_t         pyb2;
   Float_t         pzb2;
   Float_t         ebs1;
   Float_t         pxbs1;
   Float_t         pybs1;
   Float_t         pzbs1;
   Float_t         ebs2;
   Float_t         pxbs2;
   Float_t         pybs2;
   Float_t         pzbs2;

   // List of branches
   TBranch        *b_e1;   //!
   TBranch        *b_px1;   //!
   TBranch        *b_py1;   //!
   TBranch        *b_pz1;   //!
   TBranch        *b_e2;   //!
   TBranch        *b_px2;   //!
   TBranch        *b_py2;   //!
   TBranch        *b_pz2;   //!
   TBranch        *b_eb1;   //!
   TBranch        *b_pxb1;   //!
   TBranch        *b_pyb1;   //!
   TBranch        *b_pzb1;   //!
   TBranch        *b_eb2;   //!
   TBranch        *b_pxb2;   //!
   TBranch        *b_pyb2;   //!
   TBranch        *b_pzb2;   //!
   TBranch        *b_ebs1;   //!
   TBranch        *b_pxbs1;   //!
   TBranch        *b_pybs1;   //!
   TBranch        *b_pzbs1;   //!
   TBranch        *b_ebs2;   //!
   TBranch        *b_pxbs2;   //!
   TBranch        *b_pybs2;   //!
   TBranch        *b_pzbs2;   //!

   MyClass(TTree *tree=0);
   virtual ~MyClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MyClass_cxx
MyClass::MyClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("output.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("output.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

MyClass::~MyClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("e1", &e1, &b_e1);
   fChain->SetBranchAddress("px1", &px1, &b_px1);
   fChain->SetBranchAddress("py1", &py1, &b_py1);
   fChain->SetBranchAddress("pz1", &pz1, &b_pz1);
   fChain->SetBranchAddress("e2", &e2, &b_e2);
   fChain->SetBranchAddress("px2", &px2, &b_px2);
   fChain->SetBranchAddress("py2", &py2, &b_py2);
   fChain->SetBranchAddress("pz2", &pz2, &b_pz2);
   fChain->SetBranchAddress("eb1", &eb1, &b_eb1);
   fChain->SetBranchAddress("pxb1", &pxb1, &b_pxb1);
   fChain->SetBranchAddress("pyb1", &pyb1, &b_pyb1);
   fChain->SetBranchAddress("pzb1", &pzb1, &b_pzb1);
   fChain->SetBranchAddress("eb2", &eb2, &b_eb2);
   fChain->SetBranchAddress("pxb2", &pxb2, &b_pxb2);
   fChain->SetBranchAddress("pyb2", &pyb2, &b_pyb2);
   fChain->SetBranchAddress("pzb2", &pzb2, &b_pzb2);
   fChain->SetBranchAddress("ebs1", &ebs1, &b_ebs1);
   fChain->SetBranchAddress("pxbs1", &pxbs1, &b_pxbs1);
   fChain->SetBranchAddress("pybs1", &pybs1, &b_pybs1);
   fChain->SetBranchAddress("pzbs1", &pzbs1, &b_pzbs1);
   fChain->SetBranchAddress("ebs2", &ebs2, &b_ebs2);
   fChain->SetBranchAddress("pxbs2", &pxbs2, &b_pxbs2);
   fChain->SetBranchAddress("pybs2", &pybs2, &b_pybs2);
   fChain->SetBranchAddress("pzbs2", &pzbs2, &b_pzbs2);
   Notify();
}

Bool_t MyClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MyClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MyClass_cxx
