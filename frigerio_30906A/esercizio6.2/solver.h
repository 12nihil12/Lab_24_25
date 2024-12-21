#ifndef solver_h
#define solver_h

#include "fun.h"

class solver{
    public: 
        solver(){N_MAX=100;}; // creates solver object with default parameters



        virtual ~solver() {;};


        virtual double find_zero(double a,double b, fun * f , double u_prec=0.001 )  =0;


        void Setprec(double epsilon) { s_prec = epsilon; }
        double Getprec() { return s_prec;}

        void set_N_max(unsigned int n ) { N_MAX = n ; }
        unsigned int get_N_max () { return N_MAX ; } 

        unsigned int get_N_iterations () { return n_iter ; } ;

        double geta(){return s_a;}
        double getb(){return s_b;}


    protected: 
        double s_a,s_b; 
        double s_prec; 
        unsigned int N_MAX, n_iter; 
}; 


class bisezione : public solver {
    public:
    bisezione (): solver() {; }; 
  virtual double find_zero(double a,double b, fun * f , double u_prec=0.001 ) override;
};

#endif