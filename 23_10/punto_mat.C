#include"punto_mat.h"
#include <cmath> 


using namespace std; 


campo_vett punto_mat::E_field(const posizione & p) const{
    campo_vett E(p);
    double r = distanza(p); 
    double C= 1/(4*8.85e-12*M_PI)*q/pow(r,3);
    E.setFx(C*x);
    E.setFy(C*y);
    E.setFz(C*z);
    return E;

}