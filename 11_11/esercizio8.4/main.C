#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <sys/stat.h>


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


if(argc!=3){
  cout << "Usage of " << argv[0] << ": <integration step> <x_0 sel>" << endl; 
  return -1; 
}

double h= atof(argv[1]); 
double sel= atoi(argv[2]);

TApplication myApp("myApp",0,0);

TGraph graph_A;
TGraph graph_x;


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

oamf->set_wf(wf);
/* 
do{

    x= sol->step(x,t,oamf,h);
    graph_A.SetPoint(j,t,x[0]);
    t=t+h; 
    j++;
  } while(t < 10*(1./beta) +1);


 */
do{

  t=0; 

  x=x_0; 
  
  oamf->set_wf(wf); 

  do{
    x= sol->step(x,t,oamf,h);
    
    t=t+h; 
  } while(t< 10*1./beta);
 
 /*   */
  do{  
    x_set=x; 
    //v= x[1]; 
    x= sol->step(x,t,oamf,h); 
  
 
    if ( x_set[1]*x[1] < 0  ) {  
      double m= (x_set[1]-x[1])/h; 
       double q=x_set[1]-m*t;
        
       A= abs(x_set[0]+(-q/m-t)*x_set[1]);
      break; 
    };

    t=t+h;  
  } while(1);

   
 /*  
  while(fabs(x[0])>A){
    A=fabs(x[0]); 
      x= sol->step(x,t,oamf,h);
    t=t+h;
  }

  */
  graph_A.SetPoint(k,wf,A);
  wf=wf+0.05;  
  
  k++; 
    
}while(wf <= 11); 


c.cd(); 
c.SetGrid(); 
graph_A.SetTitle("Ampiezza di un oscillatore forzato  di #omega=10 rad/s in funzione della forzante #omega_{f}"); 
graph_A.GetYaxis()->SetTitle("A[m]");
graph_A.GetXaxis()->SetTitle("#omega_{f} [rad/s]");
graph_A.SetMarkerColor(kBlue + 3); 
graph_A.SetLineColor(kBlue -6); 
graph_A.Draw("AL*");


c.SaveAs("graph.pdf");




myApp.Run();

return 0; 
}
