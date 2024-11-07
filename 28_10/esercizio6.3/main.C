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
    double zero= s->find_zero(M_PI*n + 0.0000001 ,(n+0.5)*M_PI - 0.0000001,p,0.00000001); 
    cout << "n: " << n << " |" << setprecision(-log10(s->Getprec())) << zero << endl; 


    }
    catch(...){
        cout << "Skipping " << n << " iteration" << endl; 
    }
}


return 0; 
}