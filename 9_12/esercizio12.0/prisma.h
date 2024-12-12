#pragma once
#include "gen_rand.h"


class prisma{

    public:
    prisma(unsigned int seed);

    void misura();
    void analisi();

    double get_A(){return i_A_c;};
    double get_B(){return i_B_c;};

    double get_th0(){return i_th0_c;};
    double get_th1(){return i_th1_c;};
    double get_th2(){return i_th2_c;};

    double get_dm1(){return i_dm1_c;};
    double get_dm2(){return i_dm2_c;};

    double get_n1(){return i_n1_c;};
    double get_n2(){return i_n2_c;};

    double get_A_t(){return i_A_t;};
    double get_B_t(){return i_B_t;};

    double get_th0_t(){return i_th0_t;};
    double get_th1_t(){return i_th1_t;};
    double get_th2_t(){return i_th2_t;};

    double get_dm1_t(){return i_dm1_t;};
    double get_dm2_t(){return i_dm2_t;};


    double get_n1_t(){return i_n1_t;};
    double get_n2_t(){return i_n2_t;};
    
    private:
    gen_rand  i_rngen;
    double i_l1,i_l2; 
    double i_a, i_sth;
    double i_A_t,i_A_c; 
    double i_B_t,i_B_c; 

    double i_n1_t, i_n1_c; 
    double i_n2_t, i_n2_c; 
    double i_dm1_t, i_dm1_c; 
    double i_dm2_t, i_dm2_c; 
    double i_th0_t, i_th0_c; 
    double i_th1_t, i_th1_c; 
    double i_th2_t, i_th2_c; 


};


