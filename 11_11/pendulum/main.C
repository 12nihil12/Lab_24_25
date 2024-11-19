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



int main(int argc, char** argv) {


if(argc!=3){
  cout << "Usage of " << argv[0] << ": <integration step> <theta_0>" << endl; 
  return -1; 
}



double h= atof(argv[1]); 
double theta_0=atof(argv[2]); 
//double sel= atoi(argv[2]); CONTROL

TApplication myApp("myApp",0,0);

TGraph myGraph;
TCanvas c; 


double l=1; 
vector <double> phi_0 {theta_0,0.}; 
vector <double> phi =phi_0; 




auto *sol = new runge_kutta(phi_0,0.); 

auto * p = new pendolo(l); 

int k=0; 
double t=0; 

phi=phi_0; 


string title = "Traiettoria pendolo" ;
c.cd(); 
c.SetGrid(); 
myGraph.SetTitle(title.c_str());
myGraph.GetXaxis()->SetTitle("x[m]");
myGraph.GetYaxis()->SetTitle("y [m]");

myGraph.SetMarkerColor(kBlue + 3); 
myGraph.SetLineColor(kBlue -6); 



while(t<70){ 


  double x=l*sin(phi[0]);
  double y=-l*cos(phi[0]);

   myGraph.SetPoint(k,x,y);
    // Draw the TGraph at each step, update the TCanvas and wait                                                                                                     

    myGraph.Draw("AL*");
    c.Update();
    gSystem->ProcessEvents();
    usleep(10000);
  
  phi= sol->step(phi,t,p,h); 

  k++; 
  t=t+h; 
}; 







c.SaveAs("graph.pdf");




myApp.Run();

return 0; 
}
