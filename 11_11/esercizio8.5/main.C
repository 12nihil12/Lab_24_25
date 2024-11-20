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
#include "TSystem.h"

#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {

/*  
if(argc!=2){
  cout << "Usage of " << argv[0] << ": <integration step> " << endl; 
  return -1; 
}
*/

double h=86400; 
char ans;

cout << "Integration step is set at " << h << "s. Do you want to change it? [Y/n]" << endl; 
cin >> ans; 
if(ans=='Y' || ans=='y'){
   cout << "Insert a new integration step:" << endl; 
  cin >> h;
  while(h <=0){
    cout << "Insert a new integration step:" << endl; 
      cin >> h; 
  }
}

//double h= atof(argv[1]); 

TApplication myApp("myApp",0,0);

TGraph myGraph;
TCanvas c; 


vector <double> z_0 {A,0.,0.}; 
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


/* 
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
  double x=z[0]*cos(z[2]);
  double y=z[0]*sin(z[2]);
  myGraph.SetPoint(k,x,y);
   
    myGraph.Draw("ALP");
    c.Update();
    gSystem->ProcessEvents();
    usleep(10000);

  vector <double> z_set= z; 
  
  z= sol->step(z,t,p,h); 


  if(z[1]*z_set[1] <0){
    double m= (z[1]-z_set[1])/h; 
    double q=z_set[1]-m*t; 
    T=-2*q/m; 
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


//cout << "B | " << B << endl;



//c.SaveAs("graph.pdf");




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
