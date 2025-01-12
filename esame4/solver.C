#include"solver.h"
#include <exception>
#include <algorithm>
#include <iostream> 


using namespace std;

double bisezione::find_zero(double a,double b, myfun2 * f , double u_prec)  {

    

    if(f->sign(a)*f->sign(b)>0){
        cout << "Per applicare il metodo di bisezione, gli estremi devono essere discordi" << endl; 
        throw 11; //math error
    }else if (f->eval(a)==0){ cout << "Zero found in " << a << endl; return a;}
    else if (f->eval(b)==0){ cout << "Zero found in "<< b << endl; return b;}

    Setprec(u_prec);
    
    s_a=min(a,b); 
    s_b=max(a,b); 

    n_iter=0; 
    double fa= f->eval(a);
    double fb= f->eval(b); 


    while(abs(s_b-s_a) > s_prec){
 
        double c = (s_b +s_a)/2; 
        if(n_iter > N_MAX){
            cout << "Numero massimo di iterazioni raggiunto." << endl; 
            break; 
        }
        if(f->eval(c)==0){
            cout << "Zero found in "<< c << endl; 
            return c;

        }else if (f->sign(c)*f->sign(getb()) <0){
            fa=f->eval(c); 
            s_a=c; 

        }else if(f->sign(c)*f->sign(geta())< 0){
            fb=f->eval(c); 
            s_b=c; 
        }
        n_iter++; 
    }
   

    return (s_b +s_a)/2; 

}