#ifndef campo_vett_h
#define campo_vett_h
#include <cmath>

#include "posizione.h"
class campo_vett : public posizione {

    public:
        campo_vett(const posizione &);
        campo_vett(const posizione &,double Fxp,double Fyp,double Fzp);
        campo_vett(double xp,double yp,double zp,double Fxp,double Fyp,double Fzp);

    //accesso

        double getFx() const {return Fx;}
        double getFy() const {return Fy;}
        double getFz() const {return Fz;}

        void setFx(double Fxp) { Fx=Fxp;}
        void setFy(double Fyp) { Fy=Fyp;}
        void setFz(double Fzp) { Fz=Fzp;}
        
    //operatori

    campo_vett & operator+=( const campo_vett & ) ;
    campo_vett operator+( const campo_vett & ) const;

        double modulo(){return sqrt(Fx*Fx+Fy*Fy+Fz*Fz);};

    private:
        double Fx;
        double Fy;
        double Fz;
};

#endif