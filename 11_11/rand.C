

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"

#include <cstdlib>


#include "lib_random.h"


int main (int argc, char ** argv){


TApplication myApp("myApp",0,0);


    seedset(); 

    int N =atoi(argv[1]); 


    TGraph u; 
    TGraph g; 


    TCanvas c1; 
    TCanvas c2; 


    for(int k=0; k <N ; k++){

       
        g.SetPoint(k,k,randunif(-1,1)); 
        //g.SetPoint(k,k,randgauss(0,1)); 
    }


    g.SetMarkerColor(9); 
    //c1.cd();
    //u.Draw("*");

    c2.cd();
    
    g.Draw("AL*"); 

    myApp.Run();
}


