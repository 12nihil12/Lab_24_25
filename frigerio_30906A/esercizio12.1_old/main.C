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



int main(int argc, char** argv) {

    TApplication app("app",0,0);


    TCanvas g("Distr","Istogramma"); 

    g.Divide(2,1);


    visc esp1(1,0.01); 
    visc esp2(1,0.005); 


    TH1F hist1("hist","Distribuzione valori #eta- R=0.01 m",100, 0,-1); 
   
    TH1F hist2("hist ","Distribuzione valori #eta - R=0.005 m",100, 0,-1); 

    hist1.StatOverflows( kTRUE );
    hist2.StatOverflows( kTRUE );

    vector <TH2F *> hist_2D_1(5);
    vector <TH2F *> hist_2D_2(5);

    hist_2D_1[0]=new TH2F("R","R",100,1,0,100,1,0);
    hist_2D_1[1]=new TH2F("t0","t0",100,1,0,100,1,0);
    hist_2D_1[2]=new TH2F("t","t",100,1,0,100,1,0);
    hist_2D_1[3]=new TH2F("l0","l0",100,1,0,100,1,0);
    hist_2D_1[4]=new TH2F("l","l",100,1,0,100,1,0);

    hist_2D_2[0]=new TH2F("R (2)","R",100,1,0,100,1,0);
    hist_2D_2[1]=new TH2F("t0 (2)","t0",100,1,0,100,1,0);
    hist_2D_2[2]=new TH2F("t (2)","t",100,1,0,100,1,0);
    hist_2D_2[3]=new TH2F("l0 (2)","l0",100,1,0,100,1,0);
    hist_2D_2[4]=new TH2F("l (2)","l",100,1,0,100,1,0);


    TCanvas c("Distr", "Distribuzione differenze valori attesi e misurati: coeff su asse y, quantita' indicata su asse x. A sinistra R 0.01 m, a destra R=0.005 m"); 

    c.Divide(2,5); 


    for(int i=0; i<1000; i++){
        esp1.misura();
        esp1.analisi();
        hist1.Fill(esp1.get_coeff_m());
        hist_2D_1[0]->Fill((esp1.get_R_m()-esp1.get_R_t()),(esp1.get_coeff_m()-esp1.get_coeff_t())); 
        hist_2D_1[1]->Fill((esp1.get_t0_m()-esp1.get_t0_t()),(esp1.get_coeff_m()-esp1.get_coeff_t())); 
        hist_2D_1[2]->Fill((esp1.get_t_m()-esp1.get_t_t()),(esp1.get_coeff_m()-esp1.get_coeff_t())); 
        hist_2D_1[3]->Fill((esp1.get_l0_m()-esp1.get_l0_t()),(esp1.get_coeff_m()-esp1.get_coeff_t())); 
        hist_2D_1[4]->Fill((esp1.get_l_m()-esp1.get_l_t()),(esp1.get_coeff_m()-esp1.get_coeff_t())); 

        esp2.misura();
        esp2.analisi();
        hist2.Fill(esp2.get_coeff_m());
        hist_2D_2[0]->Fill((esp2.get_R_m()-esp2.get_R_t()),(esp2.get_coeff_m()-esp2.get_coeff_t())); 
        hist_2D_2[1]->Fill((esp2.get_t0_m()-esp2.get_t0_t()),(esp2.get_coeff_m()-esp2.get_coeff_t())); 
        hist_2D_2[2]->Fill((esp2.get_t_m()-esp2.get_t_t()),(esp2.get_coeff_m()-esp2.get_coeff_t())); 
        hist_2D_2[3]->Fill((esp2.get_l0_m()-esp2.get_l0_t()),(esp2.get_coeff_m()-esp2.get_coeff_t())); 
        hist_2D_2[4]->Fill((esp2.get_l_m()-esp2.get_l_t()),(esp2.get_coeff_m()-esp2.get_coeff_t())); 

       
    }


    cout << "R=0.01 m | coeff: MEDIA " << hist1.GetMean() << " DVST " << hist1.GetStdDev() << endl; 
    cout << "R=0.005 m | coeff: MEDIA " << hist2.GetMean() << " DVST " << hist2.GetStdDev() << endl << endl;  
     g.cd(1); 
    gPad->SetGrid(); 
    hist1.Draw();
    g.cd(2); 
    gPad->SetGrid(); 
    hist2.Draw();

    int i=0; 
    for(int k=1; k<=10; k++){
        c.cd(k); 
        if(k%2!=0){
            hist_2D_1[i]->StatOverflows( kTRUE );
            hist_2D_1[i]->Draw(); 
        }else{
            
            hist_2D_2[i]->StatOverflows( kTRUE );
            hist_2D_2[i]->Draw(); 
            i++;
        }
    }


    cout << "***" << endl << endl; 
    cout << "R=0.01 m : FATTORE DI CORRELAZIONE (coeff,R): " << hist_2D_1[0]->GetCorrelationFactor() << endl; 
    cout << "R=0.005 m : FATTORE DI CORRELAZIONE (coeff,R): " << hist_2D_2[0]->GetCorrelationFactor() << endl; 
    cout << "R=0.01 m : FATTORE DI CORRELAZIONE (coeff,t0): " << hist_2D_1[1]->GetCorrelationFactor() << endl; 
    cout << "R=0.005 m : FATTORE DI CORRELAZIONE (coeff,t0): " << hist_2D_2[1]->GetCorrelationFactor() << endl; 
    cout << "R=0.01 m : FATTORE DI CORRELAZIONE (coeff,t): " << hist_2D_1[2]->GetCorrelationFactor() << endl; 
    cout << "R=0.005 m : FATTORE DI CORRELAZIONE (coeff,t): " << hist_2D_2[2]->GetCorrelationFactor() << endl; 
    cout << "R=0.01 m : FATTORE DI CORRELAZIONE (coeff,l0): " << hist_2D_1[3]->GetCorrelationFactor() << endl; 
    cout << "R=0.005 m : FATTORE DI CORRELAZIONE (coeff,l0): " << hist_2D_2[3]->GetCorrelationFactor() << endl; 
    cout << "R=0.01 m : FATTORE DI CORRELAZIONE (coeff,l): " << hist_2D_1[4]->GetCorrelationFactor() << endl; 
    cout << "R=0.005 m : FATTORE DI CORRELAZIONE (coeff,l): " << hist_2D_2[4]->GetCorrelationFactor() << endl; 

    cout << endl << "La maggiore fonte di errore è la misura del raggio della sferetta" << endl; 
   
    
    app.Run();
    

  return 0; 
}