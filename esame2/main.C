#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <filesystem>
#include <exception> 

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TColor.h"
#include "TSystem.h"
#include "TH1F.h"

#include "gen_rand.h"
#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;



int main(int argc, char** argv) {

  TGraph graph_err ;


  vector <double> x_0 {1.,0.}; 
  vector <double> x =x_0; 
    
  TApplication myApp("myApp",0,0);



  auto * oam = new oscillatore_armonico(1.15,0.01); 
  auto * eq = new runge_kutta(x_0,0.); 


  
  double t=0; 
  double err; 



  double h=0.1; 

  cout << "Passo: " << h; 




 for(int k=0; k < 43/h; k++){
  
    x= eq->step(x,t,oam,h); 
    t=t+h; 
    
      
  }



  double A= sqrt(x_0[0]*x_0[0]*(1+0.01*0.01/(4*1.15*1.15)));
  double phi=-0.01/(2*1.15);


  err=x[0]-A*pow(M_E,-0.01/2*t)*cos(1.15*t+phi);

    

  cout << endl << "scostamento da soluzione esatta " << abs(err) << endl;

  double sv=x[0]; 

  h=h/2; 

  x=x_0; 


 for(int k=0; k < 43/h; k++){
  
    x= eq->step(x,t,oam,h); 
    t=t+h; 
 
  
  }

 err=abs(x[0]-sv)*16./15; 

  cout << " | x(43 s)= " << x[0] <<  " | errore:  " << err << endl; 

  double c= err/pow(2*h,4); 

  h=pow(50e-6/c,0.25); 

  cout << "Il passo necessario per una precisione di 50e-6 metri è " << h<< endl; 


  gen_rand gen(1);


  double dvst[5]={3,5,8,12,15}; 
  TGraph g; 

  h=0.1;

  for(int e=0;e< 5; e++){

    TH1F hist("x","x",100,1,0); 
    hist.StatOverflows(true); 
    for(int i=0; i < 10000; i++){
      x_0={1.,gen.gauss(0,dvst[e]*1e-3)};  
      x=x_0;
      t=0;

      for(int k=0; k < 43/h; k++){
        x= eq->step(x,t,oam,h); 
        t=t+h; 

      }
      hist.Fill(x[0]);



  }

  g.SetPoint(e,dvst[e],hist.GetStdDev()); 
  
  cout << "sv=" <<dvst[e]*1e-3 <<"  || x(43 s) --> Media: " <<hist.GetMean() << " dvst " << hist.GetStdDev() << endl; 


  }

  TCanvas d;
  g.SetMarkerStyle(20);
  g.SetMarkerColor(kRed); 

  g.Draw("ALP"); 

  g.GetXaxis()->SetTitle("s_v [ x 10^-3]");
  g.GetYaxis()->SetTitle("s_x(43 s)");

  d.SetGrid();


  myApp.Run();




return 0; 
}
