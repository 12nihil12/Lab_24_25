#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include"fun.h"
#include "solver.h"
using namespace std;

int main(int argc, char** argv) {
auto *p = new myfun(); 


auto * s = new bisezione(); 


for(int n =1; n<=20; n++){
    try{
    double zero= s->find_zero(M_PI*n,(n+0.5)*3.14,p,0.001); 
    cout << setprecision(-log10(s->Getprec())) << zero << endl; 


    }
    catch(...){
        cout << "Skipping" << n << " iteration" << endl; 
    }
}


return 0; 
}