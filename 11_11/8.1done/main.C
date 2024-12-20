#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"


#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;

int main(int argc, char** argv) {

if ( argc!=2 ) {
    std::cerr << "Usage: " << argv[0] << " <stepsize>" << std::endl;
    return -1;
  }  

  TApplication myApp("myApp",0,0);

TGraph graph_x_t ;
TGraph graph_err ;

vector <double> x_0 {0.,1.}; 
vector <double> x =x_0; 

print(x_0);
double h= atof(argv[1]); 

auto * oam = new oscillatore_armonico(1.); 

auto * eq = new eulero(x_0,0.); 

int k=0; 
double t=0; 
double err; 
    do{
      x= eq->step(x,t,h,oam); 
      t=t+h; 
      err= fabs( x[0]-sin(t));
      graph_x_t.SetPoint(k,t,x[0]);
      graph_err.SetPoint(k,k,err); 
      k++; 
  } while(t <70);


cout << t; print(x);

  TCanvas c ;
  TCanvas e ;

  c.cd();

  graph_x_t.GetXaxis()->SetTitle("Tempo [s]");
  graph_x_t.GetYaxis()->SetTitle("Posizione x [m]");
  graph_x_t.Draw("AL");

  e.cd();
 
   graph_err.GetXaxis()->SetTitle("Step");
  graph_err.GetYaxis()->SetTitle("\Delta x [m]");
  graph_err.Draw("AL");

  myApp.Run();



return 0; 
}

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


if(argc!=2){
  cout << "Usage of " << argv[0] << ": <integration step>" << endl; 
  return -1; 
}

double h= atof(argv[1]); 


TApplication myApp("myApp",0,0);

TGraph graph_T;

TCanvas c; 

double l=1; 
vector <double> phi_0 {0.1,0.}; 
vector <double> phi =phi_0; 




auto *sol = new eulero(phi_0,0.); 

auto * p = new pendolo(l, phi_0[0],9.806); 

double v; 
double m, q; 
int k=0; 

double t; 

do{

  t=0; 

  phi=phi_0; 
  do{
    
    
    
    v= phi[1]; 
    phi= sol->step(phi,t,p,h); 

    m= (v-phi[1])/h; 
    q=v-m*t; 

    /*if(phi_0[0]==0.3 || phi_0[0]==0.6 ){
      cout <<  "phi_0: " << phi_0[0] <<endl; 
      cout << "t : " << t << " | v(t) =" << v  << " v(t+h) = " <<phi[1] << endl; 
    }*/

    if( t < -q/m && -q/m < t+ h ){
      double T= -2*q/m; 

      /*if(phi_0[0]<=0.7){
        cout <<  "Phi_0 " << fixed << setprecision(1) << phi_0[0] <<  setprecision(5) << " | T=" << T << endl; 

      }*/
      cout <<  "Phi_0 " << fixed << setprecision(1) << phi_0[0] <<  setprecision(5) << " | T=" << T << endl; 
      
      graph_T.SetPoint(k,phi_0[0],T); 
      break; 
    }

    t=t+h; 
  
  } while(1);


  phi_0[0]=phi_0[0]+ 0.1; 
  
  k++; 
    
}while(phi_0[0] <= 3.1); 


c.cd(); 
c.SetGrid(); 
graph_T.SetTitle("Periodo di un pendolo di lunghezza l=1 m in funzione di #theta_{0}"); 
graph_T.GetYaxis()->SetTitle("T[s]");
graph_T.GetXaxis()->SetTitle("#theta_{0} [rad]");
graph_T.SetMarkerColor(kBlue + 3); 
graph_T.SetLineColor(kBlue -6); 
graph_T.Draw("AL*");


c.SaveAs("graph.pdf");




myApp.Run();

return 0; 
}
