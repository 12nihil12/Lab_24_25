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


class myfun:public fun_vet_base{
    public:
        myfun(double a): fun_vet_base() { i_a=a ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 

            double r=sqrt(x[0]*x[0]+x[1]*x[1]); 
            F[0]=x[2];
            F[1]=x[3]; 
            F[2]=-pow(r,-i_a)*x[3]; 
            F[3]=pow(r,-i_a)*x[2]; 

            return F; 
        }


    private:
        double i_a; 
};



class myfun2:public fun_vet_base{
    public:
        myfun2(double a): fun_vet_base() { i_a=a ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 

            double r=sqrt(x[0]*x[0]+x[1]*x[1]); 
            F[0]=x[2];
            F[1]=x[3]; 
            F[2]=-(1+pow(r,-i_a))*x[3]; 
            F[3]=(1+pow(r,-i_a))*x[2]; 

            return F; 
        }


    private:
        double i_a; 
};

#endif