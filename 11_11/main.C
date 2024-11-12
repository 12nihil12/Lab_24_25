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


//TApplication myApp("myApp",0,0);

TGraph graph_err ;

vector <double> x_0 {0.,1.}; 
vector <double> x =x_0; 

//print(x_0);

 
double h;
auto * oam = new oscillatore_armonico(1.); 

auto * eq = new eulero(x_0,0.); 

int k=0; 
double t=0; 
double err; 
for(int j=1; j < 1000; j= j*10){
  h=0.1/j;
  cout << "Passo:" << h << endl;
    do{
      x= eq->step(x,t,h,oam); 
      t=t+h; 
      
      //graph_x_t.SetPoint(k,t,x[0]);
      //graph_err.SetPoint(k,k,err); 
      k++; 
  } while(t <70);
  err= fabs( x[0]-sin(t));

  x=x_0; 
  t=0; 
  graph_err.SetPoint(j-1,h,err); 
}



  TCanvas e ;

  e.cd();
 
  e.SetLogy();
  e.SetLogx();

  graph_err.GetXaxis()->SetTitle("Step");
  graph_err.GetYaxis()->SetTitle("/Delta x [m]");
  graph_err.Draw("AL");

  e.SaveAs("graph_err.pdf");

  //myApp.Run();




return 0; 
}