#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 

#include "posizione.h"
#include "particella.h"
#include "campo_vett.h"
#include "punto_mat.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"


using namespace std;

int main(int argc, char** argv) {

//TApplication app("app",0,0);


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


  vector <double> E_v;  
  vector <double> z;  

  for (int c=100; c<= 1000 ; c++ ){
    z.push_back(c*d);
    posizione q(0,0,c*d);

    E = elettrone.E_field( q ) + protone.E_field( q ) ;
    E_v.push_back( E.modulo() );
  }

  for(int i=0; i< E_v.size();i++){
    cout << E_v[i]<< endl;
  }



  TGraph() campo;

  return 0;  
}
