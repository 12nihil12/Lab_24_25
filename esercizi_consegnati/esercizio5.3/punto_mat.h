#ifndef punto_mat_h
#define punto_mat_h

#include "particella.h"
#include "posizione.h"

#include "campo_vett.h"

class punto_mat : public particella, public posizione {

public:

  punto_mat(double m, double q, const posizione& p): particella(m,q), posizione(p){};
  punto_mat(double m, double q, double x, double y, double z):particella(m,q),posizione(x,y,z){};


  campo_vett E_field(const posizione&) const ;


};

#endif