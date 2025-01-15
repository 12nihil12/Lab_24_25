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
#include "TSystem.h"


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

  TGraph graph_A;


  TCanvas c; 


  vector <double> x_0 {0.,0.}; 
  vector <double> x =x_0; 

  double w=10;
  double beta= 1./30; 

  auto *sol = new runge_kutta(x_0,0.); 


  auto * oamf = new oscillatore_forzato(w,beta); 

  double wf=9.;
  double v;  
  vector <double> x_set; 
  int k=0; 
  int j=0;
  double t=0; 
  double A=0; 




  do{

    t=0; 

    x=x_0; 
    
    oamf->set_wf(wf); 

    for(int k=0; k<(10*1./beta)/h; k++){
      x= sol->step(x,t,oamf,h);
      
      t=t+h; 
    }
  

    do{  
      x_set=x; 
    
      x= sol->step(x,t,oamf,h); 

      if ( x_set[1]*x[1] < 0  ) {  //quando la velocità cambia segno
        double m= (x[1]-x_set[1])/h; //cerco la pendenza della secante i due punti
        double q=x_set[1]-m*t;//ricavo il termine noto
        A= abs(x_set[0]+(-q/m-t)*x_set[1]);// Cerco l'ampiezza come A=x(t_set)+ (t(v=0) -t_set)*v(t_set) 
        //A=abs(x_set[0]);
        break; 
      };

      t=t+h;  
    } while(1);


    graph_A.SetPoint(k,wf,A);
    wf=wf+0.05;  
    
    k++; 
      
  }while(wf <= 11); 


  c.cd(); 
  c.SetGrid(); 
  graph_A.SetTitle("Ampiezza di un oscillatore (#omega=10 rad/s ) smorzato (#alpha = 0.333 ) forzato in funzione della forzante #omega_{f}"); 
  graph_A.GetYaxis()->SetTitle("A[m]");
  graph_A.GetXaxis()->SetTitle("#omega_{f} [rad/s]");
  graph_A.SetMarkerColor(kBlue + 3); 
  graph_A.SetLineColor(kBlue -6); 
  graph_A.SetMarkerStyle(20);
  graph_A.Draw("ALP");






  myApp.Run();

  return 0; 
}
