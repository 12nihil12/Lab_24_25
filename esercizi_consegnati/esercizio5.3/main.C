#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 

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



  if ( argc!= 4) {
    cout << "Uso di: " << argv[0] << " <x> <y> <z> (coordinate del punto in cui calcolare il campo)" << endl;
    exit(-1); 
  }

  TApplication app("app",0,0);


  const double e =1.60217653E-19 ;
  const double me=9.1093826E-31;
  const double mp=1.6726219E-27;  
  const double d =1.E-10;

  posizione p( atof(argv[1]) , atof(argv[2]), atof(argv[3]) );
  
  punto_mat elettrone(me, -e,0.,0.,d/2.);
  punto_mat protone(mp, e,0.,0.,-d/2.);


  campo_vett E = elettrone.E_field( p ) + protone.E_field( p ) ;

  E.print(); 

  
  vector <double> E_v;  
  vector <double> z;  

  for (int c=100; c<= 1000 ; c++ ){
    z.push_back(c*d);
    posizione q(0,0,c*d);

    E = elettrone.E_field( q ) + protone.E_field( q ) ;
    E_v.push_back( E.modulo() );
  }

  TCanvas c("Campo","Campo");
  c.SetGridx();
  c.SetGridy();
  
  auto campo = new TGraph(z.size());
  for (int i=1; i < z.size(); i++){
    campo->AddPoint(z[i],E_v[i]); 
  }
  campo->SetTitle("Campo elettrico dipolo");
  campo ->GetXaxis()->SetTitle("z[m]");
  campo->GetYaxis()->SetTitle("|E| [V/m]");
  campo->SetMarkerColor(kCyan+3);
  campo->SetMarkerStyle(20);
  campo->SetMarkerSize(0.7);
  

  campo->Draw("AP"); 

  cout  << "Lungo z il campo segue un andamento: E=kz^" << setprecision(1) << (log(E_v[3]/(E_v[40]))/log(z[3]/z[40]))<< endl;
 
  cout << endl; 

  app.Run(); 
  //c.SaveAs("campo.pdf");


  

  return 0;  
}
