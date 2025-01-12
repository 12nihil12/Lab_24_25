#include "visc.h"
#include <cmath>

#define ro_0 1250
#define ro 2700
#define g 9.81


using namespace std; 
visc::visc( unsigned int seed, double R,double u_sR, double u_sl,double u_st) :
  i_rngen( seed ),
  coeff_t(0.83),
  t0_t(1),
  R_t(R),
  l0_t(0.2),
  l_t(0.6),
  st(u_st),
  sl(u_sl),
  sR(u_sR)

{ 
    
    vl_t=2*R*R/(9*coeff_t)*(ro-ro_0)*g;
    t_t=(l_t-l0_t)/vl_t+t0_t;

}

void visc::misura(){
    t0_m=i_rngen.gauss(t0_t,st);
    t_m=i_rngen.gauss(t_t,st);
    R_m=i_rngen.gauss(R_t,sR);
    l0_m=i_rngen.gauss(l0_t,sl); 
    l_m=i_rngen.gauss(l_t,sl); 

}

void visc::analisi(){
    vl_m=(l_m-l0_m)/(t_m-t0_m);
    coeff_m=2*R_m*R_m/(9*vl_m)*(ro-ro_0)*g;

}