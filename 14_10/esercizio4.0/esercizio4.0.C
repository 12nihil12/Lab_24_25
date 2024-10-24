#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <vector>
#include <string>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"


#include "in_out.h"
#include "stat.h" 

using namespace std; 





int main(int argc,char ** argv)
{
    

    TApplication app("app",0,0);
    TGraphErrors trend;

    if(argc<3){
        cout << "Syntax: <startvalue> <endvalue> " << endl; 
        return -1;
    }
    int stv=stoi(argv[1]);
    int endv=stoi(argv[2]);


    int index {0};

    for (int i=stv; i <= endv; i++){
        string nomefile= "Data/" + to_string(i) + ".txt"; 
        vector <double> v= loadff<double>(nomefile.c_str()); 
        histo_op_delta(i,v);
        double media;  
        double err;  
        calc_stat(v,media,err);

        trend.SetPoint(index, i, media);
        trend.SetPointError( index , 0 , err);
        index++;
        cout << "Anno: "<< i<< " | Delta: " << media << " +-" << err << endl; 
    }
    
    
   
    
    TCanvas c("Temperature trend","Temperature trend");
    //c.cd();
    c.SetGridx();
    c.SetGridy();

    trend.SetMarkerSize(1.0);
    trend.SetMarkerStyle(22);
    trend.SetMarkerColor(1);
    trend.SetLineColor(9);


    trend.SetTitle("Temperature trend");
    trend.GetXaxis()->SetTitle("Year");
    trend.GetYaxis()->SetTitle("Averege #Delta (#circ C) year-today");
    trend.Draw("apl");
    trend.Draw("pX");

    c.SaveAs("Temperature_trend.pdf");

    app.Run();
            

    
   return 0;
   
}