#ifndef fun_vet_base_h
#define fun_vet_base_h

#include <cmath> 
#include<vector> 
#include "vector_operation.h"


class fun_vet_base{
    public:
    fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x) const =0; 
       

};


class oscillatore_armonico:public fun_vet_base{
    public:
        oscillatore_armonico(double om): fun_vet_base() { i_om=om ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override;

    private:
        double i_om; 
};




#endif