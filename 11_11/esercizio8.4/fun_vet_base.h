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
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 
    
            F[0]=x[1];
            F[1]=-pow(i_om,2)*x[0]; 
            return F; 
        }


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


class oscillatore_forzato:public fun_vet_base{
    public:
        oscillatore_forzato(double om,double beta): fun_vet_base() { i_om=om; i_beta=beta ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size());
            F[0]=x[1];
            F[1]=-pow(i_om,2)*x[0]-i_beta*x[1]+sin(i_wf*t); 
            return F; 
        }
    void set_wf(double wf){i_wf=wf;};

    private:
        double i_om; 
        double i_beta; 
        double i_wf; 
};


vector <double>  pendolo::eval(double t, const vector <double> &x)const{

            vector <double> F(x.size()); 
    

            F[0]=x[1];
            F[1]=-i_g/i_l*sin(x[0]); 
            return F; 
        }



#endif