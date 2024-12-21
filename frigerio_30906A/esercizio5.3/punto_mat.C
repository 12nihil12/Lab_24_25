#include"punto_mat.h"
#include <cmath> 
#include "posizione.h"

using namespace std; 


campo_vett punto_mat::E_field(const posizione & p) const{
    campo_vett E(p);
    double r = distanza(p); 
    double C= 1/(4*8.85e-12*M_PI)*q/pow(r,3);
    co_cart cp=p.coord_cart(); 
    co_cart cq=coord_cart();
    E.setFx(C*(cp.x-cq.x));
    E.setFy(C*(cp.y-cq.y));
    E.setFz(C*(cp.z-cq.z));
    return E;

}