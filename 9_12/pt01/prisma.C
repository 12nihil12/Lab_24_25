#include "prisma.h"
#include <cmath>
using namespace std; 
prisma::prisma( unsigned int seed ) :
  i_rngen( seed ),
  i_l1(579.1E-9),
  i_l2(404.7E-9),
  i_a(60.*M_PI/180.),
  i_sth(0.3E-3),
  i_A_t(2.7),
  i_B_t(60000E-18)
{ 
    i_n1_t=sqrt(i_A_t+i_B_t/pow(i_l1,2)); 
    i_n2_t=sqrt(i_A_t+i_B_t/pow(i_l2,2)); 

    i_th0_t=M_PI/2; 


    i_dm1_t= 2.*asin( i_n1_t* sin (0.5 * i_a) ) - i_a ;
    i_th1_t= i_th0_t+ i_dm1_t;
    i_dm2_t= 2.*asin( i_n2_t* sin (0.5 * i_a) ) - i_a ;
    i_th2_t= i_th0_t+ i_dm2_t;



}

void prisma::misura(){
    i_th0_c=i_rngen.gauss(i_th0_t,i_sth);
    i_th1_c=i_rngen.gauss(i_th1_t,i_sth);
    i_th2_c=i_rngen.gauss(i_th2_t,i_sth);
}

void prisma::analisi(){
    i_dm1_c=i_th1_c  - i_th0_c;
    i_dm2_c=i_th2_c  - i_th0_c;
    i_n1_c=sin((i_a+i_dm1_c)/2)/sin(i_a/2);
    i_n2_c=sin((i_a+i_dm2_c)/2)/sin(i_a/2);

    i_A_c=(i_l2*i_l2*i_n2_c*i_n2_c-i_l1*i_l1*i_n1_c*i_n1_c)/(i_l2*i_l2-i_l1*i_l1 );
    i_B_c=(i_n2_c*i_n2_c-i_n1_c*i_n1_c)/( 1./(i_l2*i_l2)-1./(i_l1*i_l1 ));



}