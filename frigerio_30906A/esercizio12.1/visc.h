#pragma once
#include "gen_rand.h"



class visc{

    public:
        visc(unsigned int seed,double R,double u_sR, double u_sl,double u_st);

        void misura();
        void analisi();

        double get_coeff_t(){return coeff_t;};
        double get_coeff_m(){return coeff_m;};
        double get_R_t(){return R_t;};
        double get_R_m(){return R_m;};
        double get_l0_t(){return l0_t;};
        double get_l0_m(){return l0_m;};
        double get_l_t(){return l_t;};
        double get_l_m(){return l_m;};
        double get_t0_t(){return t0_t;};
        double get_t0_m(){return t0_m;};
        double get_t_t(){return t_t;};
        double get_t_m(){return t_m;};
        
    private:
        gen_rand  i_rngen;
        double vl_t, vl_m;
        double t0_t,t0_m;
        double t_t,t_m; 
        double R_t,R_m; 
        double l0_t, l0_m; 
        double l_t, l_m; 

        double coeff_t,coeff_m;  
        double st,sR,sl; 



};


