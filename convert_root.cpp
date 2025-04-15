#include <cstdio>
#include <istream>
#include <ostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include "math.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TRandom.h"
#include "TChain.h"
#include "TTree.h"
#include "TFile.h"
#include <algorithm>
#include <vector>
#include <iostream>

void convert_root(TString sig, TString back1,TString back2, TString rootfile)
{
  

std::ifstream in1(sig);
std::ifstream  inb1(back1);
std::ifstream  inb2(back2);

TFile *fileroot = TFile::Open(rootfile,"RECREATE");
  double tmp[17]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
  int n=0, weight;
  double Mz, cos_theta_z,cos_theta_star,m_rec;

TTree treeOUT2("TreeS"," ");
    treeOUT2.Branch("Mz", &Mz,"Mz/D");
    treeOUT2.Branch("m_rec",  &m_rec,"m_rec/D");
    treeOUT2.Branch("cos_theta_z", &cos_theta_z,"cos_theta_z/D");
    treeOUT2.Branch("cos_theta_star",  &cos_theta_star,"cos_theta_star/D");
    
    while (in1 >> tmp[0] >> tmp[1] >> tmp[2]>>tmp[3]){     
      Mz=tmp[0];
      m_rec= tmp[1];
      cos_theta_z= tmp[2];
      cos_theta_star= tmp[3];
      treeOUT2.Fill();
      }
    treeOUT2.Write();
TTree treeOUTsb1("TreeB1"," ");
    treeOUTsb1.Branch("Mz", &Mz,"Mz/D");
    treeOUTsb1.Branch("m_rec",  &m_rec,"m_rec/D");
    treeOUTsb1.Branch("cos_theta_z", &cos_theta_z,"cos_theta_z/D");
    treeOUTsb1.Branch("cos_theta_star",  &cos_theta_star,"cos_theta_star/D");
  
    while (inb1 >> tmp[0] >> tmp[1] >> tmp[2]>>tmp[3]){     
      Mz=tmp[0];
      m_rec= tmp[1];
      cos_theta_z= tmp[2];
      cos_theta_star= tmp[3];
     
      treeOUTsb1.Fill();
      }
    treeOUTsb1.Write();
TTree treeOUTsb2("TreeB2"," ");
    treeOUTsb2.Branch("Mz", &Mz,"Mz/D");
    treeOUTsb2.Branch("m_rec",  &m_rec,"m_rec/D");
    treeOUTsb2.Branch("cos_theta_z", &cos_theta_z,"cos_theta_z/D");
    treeOUTsb2.Branch("cos_theta_star",  &cos_theta_star,"cos_theta_star/D");
    
    while (inb2 >> tmp[0] >> tmp[1] >> tmp[2]>>tmp[3]){     
      Mz=tmp[0];
      m_rec= tmp[1];
      cos_theta_z= tmp[2];
      cos_theta_star= tmp[3];
      treeOUTsb2.Fill();
      }
    treeOUTsb2.Write();

fileroot->Close();	
TChain mychain1(rootfile);

mychain1.Add("fileroot/TreeS");
mychain1.Add("fileroot/TreeB1");
mychain1.Add("fileroot/TreeB2");

}


int main(int argc, char **argv)
{
if (argc <5) {
   std::cout<<"enter: r_hqq.dat r_qq.dat r_qqff.dat  fin_data.root \n";
    return 1;
  }
 convert_root(argv[1],argv[2],argv[3],argv[4]);
}

