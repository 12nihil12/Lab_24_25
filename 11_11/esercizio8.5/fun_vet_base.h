#ifndef fun_vet_base_h
#define fun_vet_base_h

#include <cmath> 
#include<vector> 
#include "vector_operation.h"

#define G 6.6742E-11 
#define M_S 1.9844E+30
#define A 147098074E+3
#define V 30.287E+3

class fun_vet_base{
    public:
    fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x) const =0; 
       

};


class terra:public fun_vet_base{
    public:
        terra(): fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 
    
        
            F[0]=x[1];
            F[1]=(V*V*A*A)/pow(x[0],3) - (G*M_S)/pow(x[0],2); 
            F[2]=(V*A)/(pow(x[0],2));  
            return F; 
        }


    
};


#endif