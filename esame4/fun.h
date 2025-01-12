#ifndef fun_h
#define fun_h


#include <cmath> 

class fun{
    public:
        virtual double eval(double x) const =0; 
        int sign(double x){
           if(eval(x)==0){return 0;} 
           else if (eval(x)>0){return 1;} 
           else{return -1;};
        }

};


class myfun:public fun{

    public:
        myfun(double l):i_l(l){;}; 

        void set_x(double u_x){x=u_x;}; 
        virtual double eval(double t)const override {
            double d=100e-6; double L=1; 
            return 1/d*cos(1/i_l*(sqrt(L*L+(x-t)*(x-t))-sqrt(L*L +x*x)));
            }


    private: 
    double i_l; 
    double x; 

};






#endif