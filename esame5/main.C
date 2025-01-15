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


#include "esp.h"
using namespace std;




double esperimento( double sR, double sT,double sV);


int main(int argc, char** argv) {

    TApplication app("app",0,0);
    
    TF1 *fit= new TF1("fit","[0]*x+[1]",0,100000);
    //fit ->SetParameter(0,1);


    TH1F g1 ("Capacità", "Capacità",100,1,0); 
    g1.StatOverflows(true); 


    esperimento(3e-2,3e-2,3e-2);
    cout << endl; 
    esperimento(0,0,3e-2);
    esperimento(3e-2,0,0);
    esperimento(0,3e-2,0);
    cout << endl << "La maggiore fonte di errore è la misura di DT" << endl << endl;

    TGraph g; 
    double ev=2; 
    
    for(int k=0; k<11; k++){

        g.SetPoint(k,ev,esperimento(3e-2,ev/100,3e-2)); 
        ev=ev+0.5; 

    }
    cout << endl << endl;

    TCanvas C1; 
    C1.cd(); 
    C1.SetGrid(); 
    g.Fit(fit);
    cout << endl << endl;


    g.SetMarkerStyle(20);
    g.GetXaxis()->SetTitle("eV (*100)"); 

    g.GetYaxis()->SetTitle("eC (*100)"); 


    g.Draw("ALP"); 


    //cout << endl<< "Ipotizzando relazione lineare : eC=m*eV + q -> m=" << fit->GetParameter(0)<< " q= " <<fit->GetParameter(1) << endl;
    cout << "Per avere un errore del 7 per cento su C mi serve un errore del " << (7-fit->GetParameter(1) )/fit->GetParameter(0) << " per cento su V" << endl; 
   

    app.Run();

  return 0; 
}



double esperimento( double sR, double sV,double sT){


    TH1F hist1("hist","hist",100, 0,-1); 
    


    esp exp1(1,sR,sV,sT); 
  

    hist1.StatOverflows( true );
   



    for(int i=0; i<1000; i++){
        exp1.misura(); 
        exp1.analisi(); 

        hist1.Fill(exp1.get_C()); 
        
     
       
    }

    cout << "eV =" << sV*100 << " |  eT=" << sT*100 << " |  eR= " <<  sR*100; 

    double ec=hist1.GetStdDev()/hist1.GetMean()*100; 

    cout << "   ->  Errore percentuale su C: "  << ec  << endl; 
  


    return ec; 

}