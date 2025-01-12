#ifndef eq_diff_h
#define eq_diff_h

#include "vector_operation.h"

class eq_diff{
    public:
     eq_diff(vector <double> x_0, double t_0) { i_t_0= t_0; i_x_0= x_0;}; 
        virtual vector <double>  step(const vector <double> &x, double t, fun_vet_base * f, double h) const =0; 
       vector <double>   get_x_0(){return i_x_0;}; 
        void set_x_0(vector <double> x_0){i_x_0=x_0;}; 

       double  get_t_0(){return i_t_0;}; 

    protected:
        vector <double> i_x_0; 
        double i_t_0; 
};


class eulero:public eq_diff {
    public:
    eulero(vector <double> x_0, double t_0) : eq_diff(x_0,t_0){;};
        virtual vector <double>  step(const vector <double> &x, double t, fun_vet_base * f, double h) const override{
            return x + h*f->eval(t,x); 
        }; 

}; 

class runge_kutta:public eq_diff {
    public:
    runge_kutta(vector <double> x_0, double t_0) : eq_diff(x_0,t_0){;};
        virtual vector <double>  step(const vector <double> &x, double t, fun_vet_base * f, double h) const override; 

}; 



vector <double>  runge_kutta::step(const vector <double> &x, double t, fun_vet_base * f, double h) const {
    vector <double> k1=  f->eval(t,x); 
    vector <double> k2=  f->eval(t+h/2,x+k1*(h/2)); 
    vector <double> k3=  f->eval(t+h/2,x+k2*(h/2)); 
    vector <double> k4=  f->eval(t+h,x+k3*h); 


    return x + (k1+2.*k2+2.*k3+k4)*(h/6); 
}; 

#endif