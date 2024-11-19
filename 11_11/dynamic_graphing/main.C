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
#include "TSystem.h"

#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;



int main(int argc, char** argv) {

    double h=0.01; 
 TApplication myApp("myApp",0,0);

  TGraph myGraph ;
  TCanvas c;
  c.cd();
  c.Update();

  string title = "Oscillatore armonico" ;
  myGraph.SetTitle(title.c_str());
  myGraph.GetXaxis()->SetTitle("Tempo [s]");
  myGraph.GetYaxis()->SetTitle("Posizione x [m]");

  int nstep = 10000;

 vector <double> x_0 {0.,1.}; 
vector <double> x =x_0; 

  auto * oam = new oscillatore_armonico(1.); 
  auto * sol = new eulero(x_0,0.); 

  double t=0; 

  for (int step=0; step<nstep; step++) {

    myGraph.SetPoint(step,t,x[0]);
    // Draw the TGraph at each step, update the TCanvas and wait                                                                                                     

    myGraph.Draw("AL*");
    c.Update();
    gSystem->ProcessEvents();
    usleep(10000);
    x = sol->step(x,t,oam,h);
    t = t+h;
  }
  myApp.Run();

return 0; 



}
