#ifndef posizione_h
#define posizione_h

#include<iomanip>
#include<iostream> 

using namespace std;
struct co_cart{
    double x;
    double y;
    double z;
};

struct co_pol{
    double r;
    double O; //angolo polare
    double p;//angolo azimutale
};

struct co_cil{
    double r;
    double O; 
    double z;
};


class posizione {


    public:
        //COSTRUTTORI
        posizione();
        posizione(double xp,double yp, double zp);
        posizione(const posizione &);

        //ACCESSO COORDINATE
        co_cart coord_cart() const;
        co_pol coord_pol()const ;
        co_cil coord_cil() const;


        //DISTANZA
        double distanza( const posizione & p ) const;

    protected:
     
        co_cart m_coord;

        
        
}; 

void print_c(co_cart cc);
 
   

#endif

