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

/*
if(argc!=2){
  cout << "Usage of " << argv[0] << ": <integration step>" << endl; 
  return -1; 
}*/

double h= atof(argv[1]); 
//double sel= atoi(argv[2]); CONTROL

TApplication myApp("myApp",0,0);

TGraph graph_T;
//TGraph graph_v; CONTROL


TCanvas c; 
//TCanvas d; CONTROL 

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
     m= (phi[1]-1)/h; 
    q=v-m*t;

    /*  CONTROL
    if(k==sel)
    {
           //cout << "graphing for" << phi_0[0] << endl; 
     graph_v.SetPoint(j,t,v);
     cout << "t " << t << " -q/m " <<  -q/m << "  t+h " << t+h <<endl; }*/ 
  
    
    if ( v*phi[1] < 0  ) {  
       T= -2.*q/m; 

      graph_T.SetPoint(k,phi_0[0],T); 
      //graph_T.SetPoint(k,phi_0[0],t); 
      break; 
    };

    t=t+h; 
    j++; 
  } while(1);
   
   /*  CONTROL
  if(k==sel)
  {
      cout << "graphing for " << phi_0[0] << endl; 

        d.cd(); 
    d.SetGrid(); 
    graph_v.SetTitle("Periodo di un pendolo di lunghezza l=1 m in funzione di #theta_{0}"); 
    graph_v.GetYaxis()->SetTitle("v[rad/s]");
    graph_v.GetXaxis()->SetTitle("t[s]");
    graph_v.SetMarkerColor(kBlue + 3); 
    graph_v.SetLineColor(kBlue -6); 
    graph_v.Draw("AL*");
    d.SaveAs("v.pdf");
    }
  */

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
