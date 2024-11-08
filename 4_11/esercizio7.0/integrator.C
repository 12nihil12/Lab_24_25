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
    cout << i_h << endl;
    for (int k=0; k< N; k++){
        i_sum= i_sum + f->eval(i_a+(0.5+k)*i_h)*i_h; 
    }

    i_integral=i_sign*i_sum;
    return i_integral;

}