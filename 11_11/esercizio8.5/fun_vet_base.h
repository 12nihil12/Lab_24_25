#ifndef fun_vet_base_h
#define fun_vet_base_h

#include <cmath> 
#include<vector> 
#include "vector_operation.h"

#define G=6.6742E-11 
#define M_S=1.9844E+30
#define d=147098074
#define v=30.287 

class fun_vet_base{
    public:
    fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x) const =0; 
       

};


class terra:public fun_vet_base{
    public:
        terra(double om): fun_vet_base() { i_om=om ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 
    

            F[0]=x[1];
            F[1]=-pow(i_om,2)*x[0]; 
            return F; 
        }


    private:
        double i_om; 
};


#endif