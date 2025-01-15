#pragma once
#include "gen_rand.h"


class esp{

    public:
    esp(unsigned int seed,double s_R_u,double s_V_u, double s_T_u);

    void misura();
    void analisi();

    
   
    double get_C(){return C_e;};



    
    private:
    gen_rand  i_rngen;
    double C_t, C_e; 
    double T1_t, T1_e; 
    double V_0_t, V_0_e; 
    double V_1_t, V_1_e; 
    double R_t,R_e; 
    double s_R,s_V,s_T;



};


