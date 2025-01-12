#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include <fstream> 

#include"fun.h"
#include "integrator.h"

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TColor.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TF1.h"
using namespace std;



int main(int argc, char** argv) {


    TApplication app("app",0,0);

    auto *f= new myfun(); 
    ofstream file_out,file_out2; 
    file_out.open("midpoint.txt"); 
    file_out2.open("midright.txt"); 

    TF1 *fit= new TF1("fit","[0]*pow(x,[1])",0,100000);
  


    double a =0; 
    double b= sqrt(M_E);


    auto * i_S = new midpoint(a,b); 
    auto * i_S2 = new midright(a,b); 
    auto * i_S3 = new media(a,b,1); 



   
    TGraph g,fh,g2,fh2; 

    double err,h,err2;

    TCanvas c("Err","Andamento della discrepanza tra il valore vero e il valore calcolato dell'integrale di f(x)) su [0,e^{1/2}]");
   
    c.Divide(2,1); 


    double r_v= 3./16*M_E*M_E; 
    cout <<r_v << endl; 
    
    double err16; 
    for(int i= 1; i <= log(1024)/log(2); i++ ){
        int s=pow(2,i); //step
        h=(b-a)/s; 
        err=fabs(r_v-i_S->calc(f,s)); 
        err2=fabs(r_v-i_S2->calc(f,s));
        if(s==16){
            err16=err; 
        } 

        
        file_out << "Step: " << setprecision(4) << left << setw(4) << s << right<< "| h: " << left << setw(14) <<h << right << " |  errore: " <<  left << setw(16) <<err << right; 
        
        file_out   << " | integrale " << i_S->get_int() << endl; 

        file_out2 << "Step: " << setprecision(4) << left << setw(4) << s << right<< "| h: " << left << setw(14) <<h << right << " |  errore: " <<  left << setw(16) <<err2 << right; 
        
        file_out2   << " | integrale " << i_S2->get_int() << endl; 
        
        g.SetPoint(i-1,s,err); 
        fh.SetPoint(i-1,h,err); 

        g2.SetPoint(i-1,s,err2); 
        fh2.SetPoint(i-1,h,err2); 

    }



    fh.Fit(fit);
   
    c.cd(1); 

   gPad->SetLogy();
   gPad->SetLogx();


    g.SetMarkerStyle(20); 
    g.SetMarkerSize(0.7); 
    g.SetMarkerColor(kRed);


   gPad->SetGrid();
    g.Draw("AP");
    g.GetXaxis()->SetTitle("N");
    g.GetYaxis()->SetTitle("err");

   
    g.SetTitle("Midpoint");
    


    double k1= fit->GetParameter(0) ; 
    double k2 = fit->GetParameter(1) ; 
    
    cout << endl<< "Midpoint| k1= " << fit->GetParameter(0) << " k2=" << fit->GetParameter(1)<<endl;
    fh2.Fit(fit);
    cout << endl<< "Midright| k1= " << fit->GetParameter(0) << " k2=" << fit->GetParameter(1)<<endl;


    


   c.cd(2); 
   gPad->SetLogy();
   gPad->SetLogx();


    g2.SetMarkerStyle(20); 
    g2.SetMarkerSize(0.7); 
    g2.SetMarkerColor(kRed);


   gPad->SetGrid();
    g2.Draw("AP");
    g2.GetXaxis()->SetTitle("N");
    g2.GetYaxis()->SetTitle("err");

   
    g2.SetTitle("Midright");



    TH1F I_m("m","m",100,1,0); 
    double med=0; 

    for(int i=0; i < 1000; i++){
      
        I_m.Fill(i_S3->calc(f,16)); 
        med=med +i_S3->get_int(); 
    }
    med=med/1000; 


    I_m.StatOverflows(true); 
    cout << "L'integrale ottenuto col metodo della media (con 16 punti, ripetuto 1000 volte) è "<< med << " e l'errore è " <<  I_m.GetStdDev() << endl; 
    double k=I_m.GetStdDev()*4;
    //double k=0.415906*4;

    
    cout << "Per avere la precisione del metodo midpoint a 16 punti, ci sarebbero voluti: "<< pow(k/err16,2) << " punti" << endl; 


    
    
    app.Run();
    return 0; 
}

