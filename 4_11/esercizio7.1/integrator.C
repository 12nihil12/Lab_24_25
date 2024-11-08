#include "integrator.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
 void integrator::I_sign( double a, double b ) {
            i_a = min(a,b);
            i_b = max(a,b);
            if ( a > b ) i_sign = -1;
            else i_sign = 1;
        }




double midpoint::calc(const fun * f, unsigned int N){
    while (N<=0){
        cout << "Number of steps must be positive" << endl; 
        cin >> N; 
    }
    i_N=N; 
    i_h=(i_b - i_a)/N; 
    //cout << i_h << endl;
    for (int k=0; k< N; k++){
        i_sum= i_sum + f->eval(i_a+(0.5+k)*i_h); 
    }

    i_integral=i_sign*i_sum*i_h;
    return i_integral;

}



double simpson::calc(const fun * f, unsigned int N){
    while (N<=0 ||  N%2!=0){
        cout << "Number of steps must be positive and even" << endl; 
        cin >> N; 
    }
    i_N=N; 
    i_h=(i_b - i_a)/N; 
    //cout << i_h << endl;
    //cout << "sum " << i_sum << endl; 
    //cout << 1./3*f->eval(i_b);
    i_sum= 1./3*f->eval(i_a) + 1./3*f->eval(i_b); 
    //cout << "sum " << i_sum << endl; 

    double m=0.; 
    for (int k=1; k< N; k++){

        m=(k%2==0)? 2:4; 

        //cout <<  f->eval(i_a +k*i_h) << endl; 

        //cout <<  m/3*f->eval(i_a +k*i_h) << endl; 

        i_sum= i_sum + m/3*f->eval(i_a +k*i_h); 
      
        
       //cout << "sum" << k << " " << i_sum << endl;  
    }

    i_integral=i_sign*i_sum*i_h;
    return i_integral;

}