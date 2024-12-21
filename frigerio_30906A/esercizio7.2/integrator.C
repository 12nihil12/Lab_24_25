#include "integrator.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <exception> 
using namespace std;



void integrator::I_sign( double a, double b ) {
    i_a = min(a,b);
    i_b = max(a,b);
    if ( a > b ) i_sign = -1;
    else i_sign = 1;
}




double midpoint::calc(const fun * f, unsigned int N){
    if (N<=0){
        cout << "Il numero di step dev'essere positivo" << endl; 
        throw 11; 
    }
    i_N=N; 
    i_h=(i_b - i_a)/N; 

    for (int k=0; k< N; k++){
        i_sum= i_sum + f->eval(i_a+(0.5+k)*i_h); 
    }

    i_integral=i_sign*i_sum*i_h;
    return i_integral;

}



double simpson::calc(const fun * f, unsigned int N){
    if (N<=0 ||  N%2!=0){
         cout << "Il numero di step dev'essere positivo e pari" << endl; 
        throw 11;
    }
    i_N=N; 
    i_h=(i_b - i_a)/N; 
    i_sum= 1./3*f->eval(i_a) + 1./3*f->eval(i_b); 
  

    float m=0.; 
    for (int k=1; k< N; k++){

        m=(k%2==0)? 2:4;
        i_sum= i_sum + m/3*f->eval(i_a +k*i_h); 
      

    }

    i_integral=i_sign*i_sum*i_h;
    return i_integral;

}

double trapezi::calc(const fun * f, unsigned int N){
    while (N<=0){
        cout << "Il numero di step dev'essere positivo" << endl; 
        cin >> N; 
    }
    i_N=N; 
    i_h=(i_b - i_a)/N; 
    i_sum= 1./2*f->eval(i_a) + 1./2*f->eval(i_b); 
    for (int k=1; k< N; k++){
        i_sum= i_sum + f->eval(i_a+k*i_h); 
    }

    i_integral=i_sign*i_sum*i_h;
    return i_integral;

}

double trapezi::calc(const fun * f, double & epsilon){
    if(epsilon <= 0){
        cout << "La precisione inserita: " << epsilon << " non è valida." << endl; 
        throw 11; 
    }else if( epsilon < 1e-13){ //max precision before weirdness happens
        cout << "(La massima precisione possibile è " << 1e-11  <<")" << endl; 
        epsilon=1e-13;  
    }

    i_h=i_b-i_a; 
    i_sum= 1./2*f->eval(i_a) + 1./2*f->eval(i_b); 
    i_integral=i_sign*i_sum*i_h; 
    i_N=1; 
    
    do{
        i_h=i_h/2; 
        i_N=2*i_N; 
      
        for(int k=1; k < i_N; k++){
          
            if(k%2!=0){
                i_sum= i_sum + f->eval(i_a+k*i_h);
            
            }
        }
        
        err(); 
        i_integral=i_sign*i_sum*i_h;

        
    }
    while(i_err>epsilon); 

    return i_integral;

}

