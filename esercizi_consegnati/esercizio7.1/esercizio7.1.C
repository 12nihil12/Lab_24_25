#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include <fstream> 

#include"fun.h"
#include "integrator.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;

int main(int argc, char** argv) {

    unsigned int N; 

    if(argc != 2){
        cout << "Uso di " << argv[0] << " : <numero step>" << endl; 
        return 0; 
    }

    TApplication app("app",0,0);

    auto *f= new myfun(); 
    ofstream file_out; 
    file_out.open("risultati.txt"); 
    N=atoi(argv[1]);

    double a =0; 
    double b= M_PI/2;



    auto * i_S = new simpson(a,b); 

   
    TGraph g; 

    double err,h;

    TCanvas c("Err","Err");

    for(int i= 1; i <= N; i++ ){
        int s=2*i; //step
        h=(b-a)/s; 
        err=fabs(1-i_S->calc(f,s)); 
        
        file_out << "Step: " << fixed <<  setprecision(-floor(log10(err))) << left << setw(4) << s   << right<< "| h: " << left << setw(14) <<h << right << " |  errore: " <<  left << setw(16) <<err << right; 
        
        file_out   << " | integrale " << i_S->get_int() << endl; 
        
        g.SetPoint(i-1,s,err); 
    }

    cout << endl << "Valore dell'integrale  calcolato con " << 2* N << " step : " << fixed << setprecision(-floor(log10(err)))<< i_S->get_int() << endl; 
    cout << "I valori per N da 2 a " << 2*N << " si possono trovare nel file <risultati.txt>" << endl;
    c.SetLogy();
    c.SetLogx();


    g.SetMarkerStyle(20); 
    g.SetMarkerSize(0.7); 
    g.SetMarkerColor(kRed);

    c.SetGrid();
    g.Draw("AP");
    g.GetXaxis()->SetTitle("N");
    g.GetYaxis()->SetTitle("err");

   
    g.SetTitle("Andamento della discrepanza tra il valore vero e il valore calcolato dell'integrale di xsin(x) su [0,#pi/2]");

    

    
    app.Run();
    return 0; 
}

