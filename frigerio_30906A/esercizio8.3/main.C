#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <exception> 

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TColor.h"

#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;



int main(int argc, char** argv) {


  if(argc!=2){
    cout << "Uso di " << argv[0] << ": <step integrazione>" << endl; 
    return -1; 
  }



  double h= atof(argv[1]); 

  TApplication myApp("myApp",0,0);

  TGraph graph_T;


  TCanvas c; 

  double l=1; 
  vector <double> phi_0 {0.1,0.}; 
  vector <double> phi =phi_0; 




  auto *sol = new runge_kutta(phi_0,0.); 

  auto * p = new pendolo(l); 

  double v; 
  double m, q; 
  int k=0; 
  int j=0;
  double t,T; 

  do{

    t=0; 
    phi=phi_0; 
    do{    

      v= phi[1]; 
      phi= sol->step(phi,t,p,h); 
      
      if ( v*phi[1] < 0  ) {  //quando la velocità cambia segno(il moto si inverte)
        m= (phi[1]-v)/h; //cerco la pendenza della retta secante i due punti 
        q=v-m*t;//ricavo il termine noto
        T= -2.*q/m; //T è 2 volte la coordinata del punto per cui la retta passa per lo 0 (la velocità va a 0)
        graph_T.SetPoint(k,phi_0[0],T); 
        break; 
      };

      t=t+h; 
      j++; 
    } while(1);
    

    phi_0[0]=phi_0[0]+ 0.1; 
    
    k++; 
      
  }while(phi_0[0] <= 3.1); 


  c.cd(); 
  c.SetGrid(); 
  graph_T.SetTitle("Periodo di un pendolo di lunghezza l=1 m in funzione di #theta_{0}"); 
  graph_T.GetYaxis()->SetTitle("T[s]");
  graph_T.GetXaxis()->SetTitle("#theta_{0} [rad]");
  graph_T.SetMarkerStyle(20); 

  graph_T.SetMarkerColor(kBlue + 3); 
  graph_T.SetLineColor(kBlue -6); 
  graph_T.Draw("ALP");



  myApp.Run();

  return 0; 
}
