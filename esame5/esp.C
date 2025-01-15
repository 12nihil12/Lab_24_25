#include "esp.h"
#include <cmath>
using namespace std; 
esp::esp( unsigned int seed ,double s_R_u,double s_V_u, double s_T_u) :
  i_rngen( seed),
  C_t(2), 
  V_0_t(12),
  V_1_t(3),
  R_t(100e3), 
  s_T(s_T_u),
  s_R(s_R_u),
  s_V(s_V_u)


{ 
    T1_t=C_t*R_t*log(V_0_t/V_1_t); 

}

void esp::misura(){
    T1_e=i_rngen.gauss(T1_t,s_T*T1_t);
    R_e=i_rngen.gauss(R_t,s_R*R_t);
    V_0_e=i_rngen.gauss(V_0_t,s_V*V_0_t);
    V_1_e=i_rngen.gauss(V_1_t,s_V*V_1_t);

}

void esp::analisi(){
    C_e=(T1_e)/(R_e*log(V_0_e/V_1_e)); 

}