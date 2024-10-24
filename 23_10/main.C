#include <iostream>
#include <cstdlib>
#include <cmath>

#include "posizione.h"
#include "particella.h"
#include "campo_vett.h"
#include "punto_mat.h"



using namespace std;

int main(int argc, char** argv) {

  if ( argc!= 4) {
    cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    exit(-1); 
  }

  const double e =1.60217653E-19 ;
  const double me=9.1093826E-31;
  const double mp=1.6726219E-27;  
  const double d =1.E-10;

  posizione p( atof(argv[1]) , atof(argv[2]), atof(argv[3]) );

  punto_mat elettrone(me, -e,0.,0.,d/2.)                            ;
  punto_mat protone(mp, e,0.,0.,-d/2.);

    //cout << p.coord_cart().x << p.coord_cart().y << p.coord_cart().z << endl;

  campo_vett E = elettrone.E_field( p ) + protone.E_field( p ) ;

  cout << "E=(" << E.getFx() << "," << E.getFy() << "," << E.getFz() << ")" << endl;

  return 0;  
}
