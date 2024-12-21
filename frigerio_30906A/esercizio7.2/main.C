#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include"fun.h"
#include "integrator.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;
int cifre_sig(double epsilon);

int main(int argc, char** argv) {

    if(argc != 2){
        cout << "Uso di " << argv[0] << " : <precisione" << endl; 
        return 0; 
    }
    
    double epsilon=atof(argv[1]); 

    double a =0; 
    double b= M_PI/2;

    auto * f= new myfun(); 
    auto * i_t = new trapezi(a,b);

    
    
    i_t->calc(f,epsilon);


    cout << "Integrale: " << fixed << setprecision(cifre_sig(i_t->get_i_err())) << i_t->get_int()  << " | errore: " << i_t->get_i_err()<< endl << endl; 
    

    return 0; 
}


int cifre_sig(double epsilon){
    int c=0;
    while(epsilon<1){
        epsilon=epsilon*10;
        c++;
    }
    return c;

}