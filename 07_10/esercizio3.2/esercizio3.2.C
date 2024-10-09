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
    
    if(argc<3){
        cout << "Syntax: <ndati> <filename>" << endl; 
        return -1;
    }
    int ndt=stoi(argv[1]);
    while (ndt < 0)
    {
        cout << "Negative dimension of dataset is not allowed. Please enter valid dimension." << endl; 
        cin >> ndt; 
    }

    cout << "Dimension of dataset: " << ndt << endl; 
    
    char * nomefile= argv[2];
    cout << "File name: " << nomefile << endl << endl; 

    TApplication app("app",0,0);

    vector <double> v= loadff<double>(nomefile);
    
   

    TH1F histo ("histo","Delta temperature 1941-today", 100, -10, 10) ;
    histo.StatOverflows( kTRUE );
    for ( int k = 0 ; k < v.size() ; k++ ) histo.Fill( v[k] );

 

    cout << "Media= " << histo.GetMean() << endl;



    TCanvas mycanvas ("Histo","Histo");
    histo.Draw();
    histo.GetXaxis()->SetTitle("measurement");

    app.Run();
        

    
   return 0;
   
}