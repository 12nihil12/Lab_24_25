#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <exception> 
#include <filesystem>


#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"


#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;



int main(int argc, char** argv) {



  cout<< "Sto controllando l'esistenza della cartella <graph/>" << endl; 

  if(!filesystem::create_directory("graph")){
    cout << "La cartella esiste già" << endl; 
  }else{
    cout << "Cartella <graph/> creata" << endl; 

  }



  TApplication myApp("myApp",0,0);

  TGraph graph_err ;

  vector <double> x_0 {0.,1.}; 
  vector <double> x =x_0; 



  double h;
  auto * oam = new oscillatore_armonico(1.); 

  auto * eq = new runge_kutta(x_0,0.); 

  double t=0; 
  double err; 
  int c=0; int g=1; 

  for(int j=1; j < 1000; j*=2){
    h=0.0001 + j*0.0001; 
    cout << "Passo:" << h << endl;
    
    TGraph graph_x_t; 
    graph_x_t.SetLineColor(kBlue);

    TCanvas cg; 
   
    bool check=1; 
    for(int k=0;k<70/h; k++){ 
    
      x= eq->step(x,t,oam,h); 
      t=t+h; 
      graph_x_t.SetPoint(k,t,x[0]); 

      

    } 

    
      string graph_print = "graph/passo_" + to_string(h) + ".pdf"; 
      cg.cd();
      cg.SetGrid(); 

      graph_x_t.GetXaxis()->SetTitle("Tempo [s]");
      graph_x_t.GetYaxis()->SetTitle("Posizione x [m]");
      graph_x_t.Draw("AL");
      cg.SaveAs(graph_print.c_str()); 
    
    
      err= fabs( x[0]-sin(t));

      x=x_0; 
      t=0; 
      graph_err.SetPoint(c,h,err); 
      c++; 

  }


  TCanvas e ;

  e.cd();

  e.SetLogy();
  e.SetLogx();
  e.SetGrid(); 
  graph_err.SetTitle("Errore commesso col metodo di Runge-Kutta in funzione del passo h"); 
  graph_err.GetXaxis()->SetTitle("h[s]");
  graph_err.GetYaxis()->SetTitle("#Delta x [m]");
  graph_err.SetMarkerStyle(20);
  graph_err.SetMarkerColor(9);
  graph_err.Draw("ALP");



  cout << "I plot x(t) relativi ai passi h considerati si trovano nella cartella <graph>" << endl; 

  myApp.Run();




  return 0; 
}
