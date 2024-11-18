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

class pendolo:public fun_vet_base{
    public:
        pendolo(double l, double theta, double g=9.80665): fun_vet_base() { i_l=l; i_theta=theta; i_g=g; }; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override;


        void set_g(double u_g){i_g=u_g;}; 
        double get_g(){return i_g;}; 

       

    private:
        double i_l; 
        double i_theta; 
        double i_g; 
        double i_T; 
};




vector <double>  pendolo::eval(double t, const vector <double> &x)const{

            vector <double> F(x.size()); 
    

            F[0]=x[1];
            F[1]=-i_g/i_l*sin(x[0]); 
            return F; 
        }



#endif