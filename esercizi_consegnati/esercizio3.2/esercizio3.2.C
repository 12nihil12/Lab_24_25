#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <vector>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "in_out.h"

using namespace std; 

int main(int argc,char ** argv)
{
    
     if(argc!=2){
        cout << "Uso di " << argv[0] << ":  <nome file>" << endl; 
        return -1;
    }

 
    char * nomefile= argv[1];
    cout << "Nome file: " << nomefile << endl << endl; 

    vector <double>  v; 

    try{
      v=loadff<double>(nomefile); 
       
    }catch(...){
        return -1; //se il file non è stato trovato chiude il programma

    }

    TApplication app("app",0,0); 

    TH1F histo ("Delta temperatura 1941-oggi","#Delta temperatura 1941-oggi", 100, -10, 10) ;
    histo.StatOverflows( kTRUE );
    for ( int k = 0 ; k < v.size() ; k++ ) histo.Fill( v[k] );

    cout << "Media= " << histo.GetMean() << endl;

    TCanvas c ("Histo","Istogramma");
    histo.Draw();
    c.SetGrid();
    histo.GetXaxis()->SetTitle("#Delta");

    app.Run();
        

    
   return 0;
   
}