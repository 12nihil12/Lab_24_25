#ifndef integrator_h
#define integrator_h
#include "fun.h"
class integrator {
    public :
        integrator( double a, double b ){I_sign(a,b); i_N=0;i_sum= 0;i_integral=0; i_h=0;}; 

        virtual double calc(const fun * f,unsigned int N) =0;

        double get_a(){return i_a ;}
        double get_b(){return i_b;}
        unsigned int get_N(){return i_N;}
        void set_a(double a){i_a=a;I_sign(i_a,i_b);}
        void set_b(double b){i_b=b;I_sign(i_a,i_b);}
        void set_a(unsigned int N){i_N=N;}
        double get_int(){return  i_integral;}


    protected:
        void I_sign( double a, double b ); 

        double i_a; 
        double i_b; 
        unsigned int i_N; 
        int i_sign; 
        double i_sum, i_integral, i_h;

};



class midpoint: public integrator{
    public:
        midpoint(double a, double b ): integrator( a, b ) { ;}; 

        virtual double calc(const fun * f,unsigned int N) override; 
         

};

class simpson: public integrator{
    public:
        simpson(double a, double b ): integrator( a, b ) { ;}; 

        virtual double calc(const fun * f,unsigned int N) override; 


};



class trapezi: public integrator{
    public:
        trapezi(double a, double b ): integrator( a, b ) { ;}; 

        virtual double calc(const fun * f,unsigned int N) override; 


    private: 
        double I_h,I_h_2; 

};
#endif