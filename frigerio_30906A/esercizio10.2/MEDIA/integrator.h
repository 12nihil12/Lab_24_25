#ifndef integrator_h
#define integrator_h
#include "fun.h"
#include "gen_rand.h"


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
 
class media: public integrator{

    public: 
        media (double a, double b, unsigned int seed): integrator( a, b ) ,i_gen (seed) {;};
        virtual double calc(const fun * f,unsigned int N) override; 
    private: 
        gen_rand i_gen; 
};

class hitormiss: public integrator{

    public: 
        hitormiss (double a, double b, unsigned int seed): integrator( a, b ), i_gen (seed){;}; 
        virtual double calc(const fun * f,unsigned int N) override {cout << "Cannot implement this method. Try calc(const fun * f,unsigned int N, double f_max)"<<endl;throw -1;}
        double calc(const fun * f,unsigned int N,double f_max); 
    private: 
        gen_rand i_gen; 
};


//***//
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
        double calc(const fun * f,double & epsilon);
        virtual double calc(const fun * f,unsigned int N) override;
        double get_i_err(){return i_err;}; 


    private: 
        void err(){i_err=4./3*fabs(i_integral-i_sum*i_sign*i_h); }//calcola l'errore
        double i_err; //salva l'errore
};

#endif