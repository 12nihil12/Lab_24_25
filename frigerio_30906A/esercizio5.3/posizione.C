#include <cmath>
#include "posizione.h"

posizione::posizione(){
    m_coord.x=0.;
    m_coord.y=0.;
    m_coord.z=0.;
}

posizione::posizione(double xp,double yp, double zp){
    m_coord.x=xp;
    m_coord.y=yp;
    m_coord.z=zp;
}


posizione::posizione(const posizione & p){ 
    m_coord=p.coord_cart();
}


co_cart posizione::coord_cart()const{
    return m_coord;
}

co_pol posizione::coord_pol()const{
    co_pol cc;
    cc.r=sqrt(m_coord.x*m_coord.x+m_coord.y*m_coord.y+m_coord.z*m_coord.z);
    cc.O=atan(m_coord.y/m_coord.x);
    cc.p=acos(m_coord.z/cc.r);
    return cc;
}


co_cil posizione::coord_cil()const{
    co_cil cc;
    cc.r=sqrt(m_coord.x*m_coord.x+m_coord.y*m_coord.y);
    cc.O=atan(m_coord.y/m_coord.x);
    cc.z=m_coord.z;
    return cc;
}

double posizione::distanza(const posizione & p ) const{
    return sqrt(pow((coord_cart().x-p.coord_cart().x),2)+pow((coord_cart().y-p.coord_cart().y),2)+pow((coord_cart().z-p.coord_cart().z),2));
}



void print_c(co_cart cc){ 
    cout << "(" << cc.x << "," << cc.y << "," << cc.z  << ") ";
    return;
}