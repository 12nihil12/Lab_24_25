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