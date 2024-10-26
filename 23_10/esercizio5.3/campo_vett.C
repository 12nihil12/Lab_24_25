#include "campo_vett.h"
#include "posizione.h"
#include <iostream> 
#include <exception> 

using namespace std;

//COSTRUTTORI
campo_vett::campo_vett(const posizione & p): posizione(p){
    Fx=0.;
    Fy=0.;
    Fz=0.;
}
campo_vett::campo_vett(const posizione & p,double Fxp,double Fyp,double Fzp): posizione(p){
    Fx=Fxp;
    Fy=Fyp;
    Fz=Fzp;
}
campo_vett::campo_vett(double xp,double yp,double zp,double Fxp,double Fyp,double Fzp): posizione(xp,yp,zp){
    Fx=Fxp;
    Fy=Fyp;
    Fz=Fzp;
}


//OPERATORI


campo_vett campo_vett::operator+( const campo_vett & F) const{
    
    
    if ( ( F.coord_cart().x!= coord_cart().x ) || ( F.coord_cart().y!= coord_cart().y ) || ( F.coord_cart().z!= coord_cart().z ) ) {
    cout << "Somma di campi vettoriali in punti diversi non ammessa" << std::endl;
    throw (-11) ; //invalid math
    } 

    campo_vett sum ( posizione( coord_cart().x,coord_cart().y, coord_cart().z) ) ; // creo un campo vettoriale nella posizione giusta
    sum.setFx( getFx() + F.getFx()) ;  
    sum.setFy( getFy() + F.getFy()) ;  
    sum.setFz( getFz() + F.getFz()) ;  
    return sum;

}


campo_vett & campo_vett::operator+=( const campo_vett & F ) {
    return (*this) = (*this)+F;
}