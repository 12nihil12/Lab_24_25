#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <fstream>
#include <exception> 


#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TColor.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TH2F.h"

#include "TF1.h"


#include "gen_rand.h"
#include "prisma.h"
using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {

    TApplication app("app",0,0);
    prisma esp(1); 

    vector <TH1F *> hist(9);
    vector <TH2F *> hist_2D(3);


   

    TCanvas g("Distr","Distribuzioni differenze valori misurati e attesi relativi alla quantita' indicata"); 
  
    g.Divide(3,4);


    hist[0]= new TH1F("#theta_{0}","#theta_{0}",100,1,0);
    hist[1]= new TH1F("#theta_{1}","#theta_{1}",100,1,0) ;
    hist[2]= new TH1F("#theta_{2}","#theta_{2}",100,1,0) ;
    hist[3]= new TH1F("#delta_{1}","#delta_{1}",100,1,0) ;
    hist[4]= new TH1F("#delta_{2}","#delta_{2}",100,1,0) ;
    hist[5]= new TH1F("n_{1}","n_{1}",100,1,0) ;
    hist[6]= new TH1F("n_{2}","n_{2}",100,1,0) ;
    hist[7]= new TH1F("A","A",100,1,0) ;
    hist[8]= new TH1F("B","B",100,1,0) ;

    hist_2D[0]=new TH2F("#delta_{1},#delta_{2}","#delta_{1},#delta_{2}",100,1,0,100,1,0);
    hist_2D[1]=new TH2F("n_{1},n_{2}","n_{1},n_{2}",100,1,0,100,1,0);
    hist_2D[2]=new TH2F("A,B","A,B",100,1,0,100,1,0);

    for(int k=0; k< hist.size();k++){
    hist[k]->StatOverflows( kTRUE );

    }
 
    double d1d2,n1n2,AB;
    d1d2=n1n2=AB=0;

    for(int i=0; i<10000; i++){
        esp.misura();
        esp.analisi();
        hist[0]->Fill(esp.get_th0()-esp.get_th0_t());
        hist[1]->Fill(esp.get_th1()-esp.get_th1_t());
        hist[2]->Fill(esp.get_th2()-esp.get_th2_t());
        hist[3]->Fill(esp.get_dm1()-esp.get_dm1_t());
        hist[4]->Fill(esp.get_dm2()-esp.get_dm2_t());
        hist[5]->Fill(esp.get_n1()-esp.get_n1_t());
        hist[6]->Fill(esp.get_n2()-esp.get_n2_t());
        hist[7]->Fill(esp.get_A()-esp.get_A_t());
        hist[8]->Fill(esp.get_B()-esp.get_B_t());

        hist_2D[0]->Fill(esp.get_dm1()-esp.get_dm1_t(),esp.get_dm2()-esp.get_dm2_t());
        d1d2=d1d2+(esp.get_dm1()-esp.get_dm1_t())*(esp.get_dm2()-esp.get_dm2_t());
        hist_2D[1]->Fill(esp.get_n1()-esp.get_n1_t(),esp.get_n2()-esp.get_n2_t());
        n1n2=n1n2+(esp.get_n1()-esp.get_n1_t())*(esp.get_n2()-esp.get_n2_t());
        hist_2D[2]->Fill(esp.get_A()-esp.get_A_t(),esp.get_B()-esp.get_B_t());
        AB=AB+(esp.get_A()-esp.get_A_t())*(esp.get_B()-esp.get_B_t()); 
    }


    hist_2D[0]->GetXaxis()->SetTitle("#delta_1");
    hist_2D[0]->GetYaxis()->SetTitle("#delta_2");


    hist_2D[1]->GetXaxis()->SetTitle("n_1");
    hist_2D[1]->GetYaxis()->SetTitle("n_2");


    hist_2D[2]->GetXaxis()->SetTitle("A");
    hist_2D[2]->GetYaxis()->SetTitle("B");


   int j=0;
   int e=0;


   for(int k=0; k<12;k++){
        if(k==5 || k==8|| k==11){
            g.cd(k+1); 
            gPad->SetGrid();
            hist_2D[j]->Draw();
            j++;
        }else{
            g.cd(k+1);
            gPad->SetGrid();
            hist[e]->Draw();
            e++;
        }
    
    }


    cout << "Theta_1 (rad) |   MEDIA:"  << hist[1]->GetMean() + esp.get_th1_t() << "    |   DEV.STD:"  <<hist[1]->GetStdDev() << endl;
    cout << "Theta_2 (rad) |   MEDIA:"  << hist[2]->GetMean() + esp.get_th2_t()<< "    |   DEV.STD:"  << hist[2]->GetStdDev() << endl;
    cout << endl;
    cout << "Delta_1 (rad) |   MEDIA:"  << hist[3]->GetMean() + esp.get_dm1_t()<< "    |   DEV.STD:"  << hist[3]->GetStdDev() << endl;
    cout << "Delta_2 (rad) |   MEDIA:"  << hist[4]->GetMean() + esp.get_dm2_t() << "    |   DEV.STD:"  << hist[4]->GetStdDev() << endl;
    cout << endl;
    
    cout << "n_1 |   MEDIA:"  << hist[5]->GetMean() + esp.get_n1_t() << "    |   DEV.STD:"  << hist[5]->GetStdDev() << endl;
    cout << "n_2 |   MEDIA:"  << hist[6]->GetMean() + esp.get_n2_t()<< "    |   DEV.STD:"  << hist[6]->GetStdDev() << endl;
    cout << endl;
    
    cout << "A        |   MEDIA:"  << hist[7]->GetMean() + esp.get_A_t()<< "   |   DEV.STD:"  << hist[7]->GetStdDev() << endl;
    cout << fixed << setprecision(0);
    cout << "B (nm^2) |   MEDIA:"  << (hist[8]->GetMean() + esp.get_B_t())*1E18<< "    |   DEV.STD:"  << (hist[8]->GetStdDev())*1E18<< endl;
    cout << endl << "Coefficienti di correlazione" << endl; 

    cout << fixed << setprecision(2);
    cout << "r(delta_1,delta_2) :  " << (d1d2/10000 - hist[3]->GetMean()*hist[4]->GetMean() )/(hist[3]->GetStdDev()*hist[4]->GetStdDev() ) << endl;
    cout << "r(n_1,n_2)         :  " << (n1n2/10000 - hist[5]->GetMean()*hist[6]->GetMean() )/(hist[5]->GetStdDev()*hist[6]->GetStdDev() ) << endl;
    
    cout << "r(A,B)             : " << (AB/10000 - hist[7]->GetMean()*hist[8]->GetMean() )/(hist[7]->GetStdDev()*hist[8]->GetStdDev() )<<endl;

    app.Run();

  return 0; 
}