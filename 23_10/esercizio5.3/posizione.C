#include <cmath>
#include "posizione.h"

   posizione::posizione(){
        x=0.;
        y=0.;
        z=0.;
    }

    posizione::posizione(double xp,double yp, double zp){
        x=xp;
        y=yp;
        z=zp;
    }


    posizione::posizione(const posizione & p){
        co_cart cc=p.coord_cart();
        x=cc.x;
        y=cc.y;
        z=cc.z;
    }


    co_cart posizione::coord_cart()const{
        co_cart cc;
        cc.x=x;
        cc.y=y;
        cc.z=z;
        return cc;
    }

    co_pol posizione::coord_pol()const{
        co_pol cc;
        cc.r=sqrt(x*x+y*y+z*z);
        cc.O=atan(y/x);
        cc.p=acos(z/cc.r);
        return cc;
    }


    co_cil posizione::coord_cil()const{
        co_cil cc;
        cc.r=sqrt(x*x+y*y);
        cc.O=atan(y/x);
        cc.z=z;
        return cc;
    }

    double posizione::distanza(const posizione & p ) const{
        return sqrt(pow((coord_cart().x-p.coord_cart().x),2)+pow((coord_cart().y-p.coord_cart().y),2)+pow((coord_cart().z-p.coord_cart().z),2));
    }



void print(co_cart cc){  cout << cc.x << "    " << cc.y << "    " << cc.z << endl;
return;}