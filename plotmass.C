#include <TCanvas.h>
#include <TStyle.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TPad.h>
#include <TH2.h>
#include <TMath.h>
#include <TLatex.h>

#include <TF1.h>
#include <TH1.h>

#include <TCut.h>
#include <TROOT.h>
#include <TChain.h>
#include "TCanvas.h"
// #include "RooPlot.h"
#include "TFile.h"
#include "TH1D.h"
#include "TRandom.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1F.h"

// using namespace Root;
void plotmass()
{
  TCanvas *c1 = new TCanvas("c1", "sary_recoil_mass", 700, 500);
  // c1->SetBorderSize(6);

  TFile *f1 = TFile::Open("f_data.root");
  TTree *tree = (TTree *)gDirectory->Get("TreeS");
  TH1F *mrecs = new TH1F("mrecs", "", 100, 0, 20);
  tree->Project("mrecs", "m_rec");

  // std::cout<<" eto e"<<std::endl;
  TFile *f2 = TFile::Open("f_data.root");
  TTree *tree1 = (TTree *)gDirectory->Get("TreeB1");
  TH1F *bkg1 = new TH1F("bkg1", "", 100, 0, 20);
  tree1->Project("bkg1", "m_rec");

  TFile *f3 = TFile::Open("f_data.root");
  TTree *tree2 = (TTree *)gDirectory->Get("TreeB2");
  TH1F *bkg2 = new TH1F("bkg2", "", 100,0 , 20);
  tree2->Project("bkg2", "m_rec");

  mrecs->Scale(0.99);
  bkg1->Scale(0.9);
  bkg2->Scale(0.9);
  
  bkg1->Draw("HIST");
  bkg2->Draw("HISTsame");
  mrecs->Draw("HISTsame");

  bkg1->GetXaxis()->SetTitle(" recoil_mass [GeV]");
  bkg1->GetYaxis()->SetTitle("events/23 GeV");

  mrecs->SetLineColor(kGreen);

  bkg1->SetFillStyle(3335);
  bkg1->SetFillColor(kRed);
  bkg1->SetLineColor(kBlack);

  bkg2->SetFillStyle(3335);
  bkg2->SetFillColor(kBlue);
  bkg2->SetLineColor(kGray);

  bkg1->SetStats(0);

  TLegend *leg = new TLegend(0.57, 0.8, 0.86, 0.91);
  leg->AddEntry(mrecs, "Signal ", "f");
  leg->AddEntry(bkg1, "Backgrounds1", "f");
  leg->AddEntry(bkg2, "Backgrounds2", "f");

  leg->SetTextSize(0.05);
  leg->Draw();
  c1->SaveAs("Recoil_mass.png");
  //////////////////////////////////////////////////
  TCanvas *c2 = new TCanvas("c2", "sary_MZ", 700, 500);
  // c2->SetBorderSize(6);

  
  TH1F *m_z = new TH1F("m_z", "", 100, 0, 400);
  tree->Project("m_z", "Mz");

  // std::cout<<" eto e"<<std::endl;
  
  TH1F *bkg1z = new TH1F("bkg1z", "", 100, 0, 400);
  tree1->Project("bkg1z", "Mz");

  
  TH1F *bkg2z = new TH1F("bkg2z", "", 100,0 , 400);
  tree2->Project("bkg2z", "Mz");

  m_z->Scale(0.99);
  bkg1z->Scale(0.9);
  bkg2z->Scale(0.9);
  
  bkg1z->Draw("HIST");
  bkg2z->Draw("HISTsame");
  m_z->Draw("HISTsame");

  bkg1z->GetXaxis()->SetTitle("Mz [GeV]");
  bkg1z->GetYaxis()->SetTitle("events/23 GeV");

  m_z->SetLineColor(kGreen);

  bkg1z->SetFillStyle(3335);
  bkg1z->SetFillColor(kRed);
  bkg1z->SetLineColor(kBlack);

  bkg2z->SetFillStyle(3335);
  bkg2z->SetFillColor(kBlue);
  bkg2z->SetLineColor(kGray);

  bkg1z->SetStats(0);

  TLegend *leg1 = new TLegend(0.57, 0.8, 0.86, 0.91);
  leg1->AddEntry(m_z, "Signal ", "f");
  leg1->AddEntry(bkg1z, "Backgrounds1", "f");
  leg1->AddEntry(bkg2z, "Backgrounds2", "f");

  leg1->SetTextSize(0.05);
  leg1->Draw();
  c2->SaveAs("Z_mass.png");

/////////////////////////////////////////////////////
  TCanvas *c3 = new TCanvas("c3", "sary_cos_theta_z", 700, 500);
  // c3->SetBorderSize(6);

  
  TH1F *cos_theta = new TH1F("cos_theta", "", 100, -1.5, 1.5);
  tree->Project("cos_theta", "cos_theta_z");

  // std::cout<<" eto e"<<std::endl;
 
  TH1F *bkg11 = new TH1F("bkg11", "", 100, -1.5, 1.5);
  tree1->Project("bkg11", "cos_theta_z");

  
  TH1F *bkg22 = new TH1F("bkg22", "", 100,-1.5, 1.5);
  tree2->Project("bkg22", "cos_theta_z");

  cos_theta->Scale(0.99);
  bkg11->Scale(0.9);
  bkg22->Scale(0.9);
  
  bkg11->Draw("HIST");
  bkg22->Draw("HISTsame");
  cos_theta->Draw("HISTsame");

  bkg11->GetXaxis()->SetTitle(" cos_theta_z ");
  bkg11->GetYaxis()->SetTitle("events/23 GeV");

  cos_theta->SetLineColor(kGreen);

  bkg11->SetFillStyle(3335);
  bkg11->SetFillColor(kRed);
  bkg11->SetLineColor(kBlack);

  bkg22->SetFillStyle(3335);
  bkg22->SetFillColor(kBlue);
  bkg22->SetLineColor(kGray);

  bkg11->SetStats(0);

  TLegend *leg2 = new TLegend(0.57, 0.8, 0.86, 0.91);
  leg2->AddEntry(cos_theta, "Signal ", "f");
  leg2->AddEntry(bkg11, "Backgrounds1", "f");
  leg2->AddEntry(bkg22, "Backgrounds2", "f");

  leg2->SetTextSize(0.05);
  leg2->Draw();
  c3->SaveAs("cos_theta_z.png");

  /////////////////////////////////////////////
   TCanvas *c4 = new TCanvas("c4", "sary_cos_theta_star", 700, 500);
  // c3->SetBorderSize(6);

  
  TH1F *cos_theta_s = new TH1F("cos_theta_s", "", 100, -1.5, 1.5);
  tree->Project("cos_theta_s", "cos_theta_star");

  // std::cout<<" eto e"<<std::endl;
  
  TH1F *bkg111 = new TH1F("bkg111", "", 100, -1.5, 1.5);
  tree1->Project("bkg111", "cos_theta_star");

  
  TH1F *bkg222 = new TH1F("bkg222", "", 100,-1.5, 1.5);
  tree2->Project("bkg222", "cos_theta_star");

  cos_theta->Scale(0.99);
  bkg111->Scale(0.9);
  bkg222->Scale(0.9);
  
  bkg111->Draw("HIST");
  bkg222->Draw("HISTsame");
  cos_theta_s->Draw("HISTsame");

  bkg111->GetXaxis()->SetTitle("cos_theta_star");
  bkg111->GetYaxis()->SetTitle("events/23 GeV");

  cos_theta_s->SetLineColor(kGreen);

  bkg111->SetFillStyle(3335);
  bkg111->SetFillColor(kRed);
  bkg111->SetLineColor(kBlack);

  bkg222->SetFillStyle(3335);
  bkg222->SetFillColor(kBlue);
  bkg222->SetLineColor(kGray);

  bkg111->SetStats(0);

  TLegend *leg3 = new TLegend(0.57, 0.8, 0.86, 0.91);
  leg3->AddEntry(cos_theta_s, "Signal ", "f");
  leg3->AddEntry(bkg111, "Backgrounds1", "f");
  leg3->AddEntry(bkg222, "Backgrounds2", "f");

  leg3->SetTextSize(0.05);
  leg3->Draw();
  c4->SaveAs("cos_theta_star.png");
}
