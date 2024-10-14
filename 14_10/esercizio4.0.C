#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <vector>
#include <string>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"

#include "in_out.h"
#include "stat.h" 

using namespace std; 





int main(int argc,char ** argv)
{
    

    TApplication app("app",0,0);

    if(argc<3){
        cout << "Syntax: <startvalue> <endvalue> " << endl; 
        return -1;
    }
    int stv=stoi(argv[1]);
    int endv=stoi(argv[2]);


    vector <double> delta_mean; 
    vector <int> year;

    for (int i=stv; i <= endv; i++){
        delta_mean.push_back(calc_mean_delta(i)); 
        year.push_back(i); 
    }
    
     print<double>("Output.dat", delta_mean);
   
    
 
        

    
   return 0;
   
}