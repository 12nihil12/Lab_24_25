#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include"fun.h"
#include "integrator.h"
using namespace std;

int main(int argc, char** argv) {

unsigned int N; 

if(argc != 2){
    cout << "Usage of " << argv[0] << " : <number of intervals>" << endl; 
    return 0; 
} else if(atoi(argv[1])<=0){
    cout << "Please enter a positive number of intervals" << endl; 
    return 0; 
}

N=atoi(argv[1]);



auto *f= new myfun(); 




auto * integral = new midpoint(0, M_PI/2); 

cout << integral->calc(f,N) << endl;



return 0; 
}