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


vector <int> convert(double s); 


int main(int argc, char** argv) {


  double h=86400; 
  char ans;

  cout << "Lo step di integrazione è fissato a " << h << "s. Vuole modificarlo? [Y/n]" << endl; 
  cin >> ans; 
  if(ans=='Y' || ans=='y'){
    cout << "Inserire un nuovo step di integrazione:" << endl; 
    cin >> h;
    while(h <=0){
      cout << "Inserire un nuovo step di integrazione h>0:" << endl; 
        cin >> h; 
    }
  }



  TApplication myApp("myApp",0,0);

  TGraph myGraph;
  TCanvas c; 


  //vector <double> z_0 {A,0.,0.}; VERSIONE IN COORDINATE POLARI
  vector <double> z_0 {A,0.,0.,V}; 

  vector <double> z =z_0; 

  auto *sol = new runge_kutta(z_0,0.); 


  auto * p = new terra(); 


  string title = "Traiettoria terra" ;
  c.cd(); 
  c.SetGrid(); 
  myGraph.SetTitle(title.c_str());
  myGraph.GetXaxis()->SetTitle("x[m]");
  myGraph.GetYaxis()->SetTitle("y[m]");
  myGraph.SetMarkerStyle(43);
  myGraph.SetMarkerColor(kGreen + 3); 
  myGraph.SetLineColor(kGreen -6); 

  int k=0; 
  double t=0; 

  double B,T; 


  /* VERSIONE IN COORDINATE POLARI
  while(t<31622400){ 
    double x=z[0]*cos(z[2]);
    double y=z[0]*sin(z[2]);
    //cout << "x |" << x << " y  | " << y <<endl; 

    myGraph.SetPoint(k,x,y);
    
      myGraph.Draw("AL*");
      c.Update();
      gSystem->ProcessEvents();
      usleep(10000);
    
    z= sol->step(z,t,p,h); 

    k++; 
    t=t+h; 
  }; 
  */


  do{
    //VERSIONE IN COORDINATE POLARI
    //double x=z[0]*cos(z[2]);
    //double y=z[0]*sin(z[2]);
    //myGraph.SetPoint(k,x,y);
    myGraph.SetPoint(k,z[0],z[2]);
    
    myGraph.Draw("ALP");
    c.Update();
    gSystem->ProcessEvents();
    //usleep(10000);

    vector <double> z_set= z; 
    
    z= sol->step(z,t,p,h); 

    
    
    if(z[1]*z_set[1] <0 ){
      double m= (z[1]-z_set[1])/h; 
      double q=z_set[1]-m*t; 
      T= -2.*q/m; 
      B=abs(z_set[0]+(-q/m-t)*z_set[1]); 
    
      z=z_set;
      break; 
    }

  
    k++; 
    t=t+h; 
  }while(1); 


  vector <int> T_d=convert(T); 
  cout << endl << "***" <<endl; 

  cout << "T = " <<  T << " s " << "  ||  " << T_d[0]<< " d " << T_d[1] << " h " <<  endl; 
  cout << "r_perielio/r_afelio = " << A/B << endl; 

  cout << "***" <<endl; 



  while(t<T){ 

    //VERSIONE IN COORDINATE POLARI
    //double x=z[0]*cos(z[2]);
    //double y=z[0]*sin(z[2]); 
    //myGraph.SetPoint(k,x,y);
    myGraph.SetPoint(k,z[0],z[2]);
    
    myGraph.Draw("ALP");
    c.Update();
    gSystem->ProcessEvents();
    //usleep(10000);

    z= sol->step(z,t,p,h); 

    k++; 
    t=t+h; 
  }; 



  usleep(20000); 


  TGraph ros;
  TCanvas c2; 



  auto * q = new rosetta(); 

  title = "Rosetta (passo 10 d)" ;
  c2.cd(); 
  c2.SetGrid(); 
  ros.SetTitle(title.c_str());
  ros.GetXaxis()->SetTitle("x[m]");
  ros.GetYaxis()->SetTitle("y[m]");
  ros.SetMarkerStyle(8);
  ros.SetMarkerColor(kMagenta + 3); 
  ros.SetLineColor(kMagenta-6); 

  k=0; 

  z=z_0; 

  h=864000;

  do{
   
    ros.SetPoint(k,z[0],z[2]);
    ros.Draw("ALP");
    c2.Update();
    gSystem->ProcessEvents();


    vector <double> z_set= z; 

    z= sol->step(z,t,q,h); 


    k++; 
    t=t+h; 
    
  }while(k<2000); 



  myApp.Run();

  return 0; 
}


vector <int> convert(double T_s){
  vector <int> T; 
  int g=T_s/86400; 
  int h=(T_s - 86400*g)/3600; 

  T.push_back(g); 
  T.push_back(h); 

  return T; 
}
