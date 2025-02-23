#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip> 

#include"fun.h"
#include "integrator.h"

using namespace std;
int main(int argc, char** argv) {

    if(argc != 2){
        cout << "Uso di " << argv[0] << " : <precisione>" << endl; 
        return 0; 
    }
    
    double epsilon=atof(argv[1]); 

    double a =0; 
    double b= M_PI/2;

    auto * f= new myfun(); 
    auto * i_t = new trapezi(a,b);

    
    
    i_t->calc(f,epsilon);


    cout << "Integrale: " << fixed << setprecision(-floor(log10(i_t->get_i_err()))) << i_t->get_int()  << " | errore: " << i_t->get_i_err()<< endl << endl; 
    

    return 0; 
}

