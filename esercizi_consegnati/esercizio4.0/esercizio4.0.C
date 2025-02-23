#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <iomanip>
#include <vector>
#include <string>
#include <filesystem>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"


#include "in_out.h"
#include "stat.h" 

using namespace std; 





int main()
{

    cout<< "Sto controllando l'esistenza della cartella <graph/>" << endl; 

    if(!filesystem::create_directory("graph")){
        cout << "La cartella esiste già" << endl; 
    }else{
        cout << "Cartella <graph/> creata" << endl; 

    }

    
    TApplication app("app",0,0);
    
    TGraphErrors trend;

    int index=0;

    vector <double> v;
    

    ofstream fileout;
    fileout.open("Risultati.txt"); 


    for (int i=1941; i <=2023; i++){
        string nomefile= "TemperatureMilano/" + to_string(i) + ".txt"; 
        try{
        v=loadff<double>(nomefile.c_str());
        }catch(...){
            return -1; //se il file non è stato trovato chiude il programma

        }
        histo_op_delta(i,v); //crea e stampa il grafico per ogni anno
        double media;  
        double err;  
        calc_stat(v,media,err);//calcola e salva media e deviazione standard per ogni anno

        trend.SetPoint(index, i, media);
        trend.SetPointError( index , 0 , err);
        index++;
        fileout << "Anno: "<<  i<< " | Delta: " <<  fixed << setprecision(1) <<media << " +-" << err << endl; 
        cout << "Anno: "<<  i<< " | Delta: " <<  fixed << setprecision(1) <<media << " +-" << err << endl; 
    }
    

    
    TCanvas c("trend","trend");
    c.SetGridx();
    c.SetGridy();

    trend.SetMarkerSize(1.0);
    trend.SetMarkerStyle(22);
    trend.SetMarkerColor(1);
    trend.SetLineColor(9);


    trend.SetTitle("Trend di #Delta T per il range 1941-2023");
    trend.GetXaxis()->SetTitle("Anno");
    trend.GetYaxis()->SetTitle("#Delta T(#circ C) (anno-oggi) medio");
    trend.Draw("apl");
    trend.Draw("pX");

    c.SaveAs("trend.pdf");

    app.Run();
            

    
   return 0;
   
}