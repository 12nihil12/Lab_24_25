#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <exception> 
#include <fstream> 

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TColor.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TF1.h"

using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {

    TApplication app("app",0,0);


    TF1 *fit= new TF1("fit","[0]/sqrt(x)",0,100000);
    fit ->SetParameter(0,0.8);
    
    ifstream filein; 

    vector <TH1F *> h_v (6); 
    TCanvas c; 
    c.Divide(3,2); 

    int N=500;
    TGraph stdev; 
    
    for(int k= 0; k<6; k++){
    
        if(k!=0){
        N=(k%2!=0)?N*2: N*5; 
        }
        
        string name = "N="+to_string(N); 
        h_v[k]=new TH1F(name.c_str(),name.c_str(),400,0.80,1.20 );
    
        cout << "N=" << N << endl; 
        
        name = "int_values/N_" +to_string(N) + ".txt"; 
    
        filein.open(name.c_str()); 

        if(filein.fail()){
            cout<< "File not trovato" << endl; 
            return -1; 
        }

        for(int i=0;i< 10000;i++){
            double i_v; 
            filein >> i_v; 
            h_v[k]->Fill(i_v); 
        }


    
        c.cd(k+1);
        gPad->SetGrid();
        h_v[k]->Draw(); 
        stdev.AddPoint(N,h_v[k]->GetStdDev()); 
        filein.close();
    }

    stdev.Fit(fit);


    cout << endl<< "k=" << fit->GetParameter(0)<<endl;

    cout <<"Numero di punti necessari per una precisione di 0.001 : "<< pow(fit->GetParameter(0)/0.001,2);
    TCanvas c_2; 

    c_2.cd(); 
    c_2.SetGrid(); 
    stdev.GetXaxis()->SetTitle("N");
    stdev.GetYaxis()->SetTitle("Errore");
    c_2.SetLogx();
    c_2.SetLogy();

    stdev.SetTitle("Andamento dell'errore");
    stdev.SetMarkerStyle(20);
    stdev.SetMarkerColor(kRed +3);
    stdev.SetLineColor(kRed-4);
    stdev.Draw("ALP"); 
    app.Run();
    return 0; 
}