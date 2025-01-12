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
#include "visc.h"
using namespace std;


vector <TH1F>  esp( double sR, double sl,double st); 


int main(int argc, char** argv) {

    TApplication app("app",0,0);


    vector <TH1F> hist; 


    hist=esp(0.0001,0.001,0.01); 



    TCanvas g("Distr","Istogramma"); 

    g.Divide(2,1);


    g.cd(1); 
    gPad->SetGrid(); 
    hist[0].Draw();
    g.cd(2); 
    gPad->SetGrid(); 
    hist[1].Draw();

    cout << endl << "***" << endl; 
    esp(0,0,0.01); 
    esp(0,0.001,0); 
    esp(0.0001,0,0); 
   

    


 



    cout << endl << "La maggiore fonte di errore è la misura del raggio della sferetta" << endl; 
   
    
    app.Run();
    

  return 0; 
}


vector <TH1F> esp( double sR, double sl,double st){


    TH1F hist1("hist","Distribuzione valori #eta- R=0.01 m",100, 0,-1); 
    TH1F hist2("hist ","Distribuzione valori #eta - R=0.005 m",100, 0,-1); 
  


    visc esp1(1,0.01,sR,sl,st); 
    visc esp2(1,0.005,sR,sl,st); 

    hist1.StatOverflows( kTRUE );
    hist2.StatOverflows( kTRUE );




    for(int i=0; i<1000; i++){
        esp1.misura();
        esp1.analisi();
        hist1.Fill(esp1.get_coeff_m());
       
        esp2.misura();
        esp2.analisi();
        hist2.Fill(esp2.get_coeff_m());

       
    }

    cout << "sR =" << sR << " |  sl=" << sl << " |  st= " <<  st << endl; 

    cout << "R=0.01 m | coeff: MEDIA " << hist1.GetMean() << " DVST " << hist1.GetStdDev() << endl; 
    cout << "R=0.005 m | coeff: MEDIA " << hist2.GetMean() << " DVST " << hist2.GetStdDev() << endl << endl;  
   
    vector <TH1F> v; 
    v.push_back(hist1); 
    v.push_back(hist2); 


    return v; 

}