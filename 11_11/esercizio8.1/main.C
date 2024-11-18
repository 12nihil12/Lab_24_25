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


#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;



int main(int argc, char** argv) {


TApplication myApp("myApp",0,0);

TGraph graph_err ;

vector <double> x_0 {0.,1.}; 
vector <double> x =x_0; 

//print(x_0);
cout << "Checking existence of <graph/> directory" << endl; 
if( mkdir("graph",0777) !=0){
  if(errno==EEXIST){
    cout << "Directory already exists." << endl; 
  } else{
    cout << "Unexpected error" << endl; 
    return 0; 
  }
}else{
  cout << "Directory <graph/> created" << endl; 
}

double h;
auto * oam = new oscillatore_armonico(1.); 

auto * eq = new eulero(x_0,0.); 

int k=0; 
double t=0; 
double err; 
int c=0; int g=1; 


for(int j=1; j < 1000; j++){
  h=0.0001 + j*0.0001; 
  cout << "Passo:" << h << endl;
  
   TGraph graph_x_t; 
    TCanvas cg; 
  k=0; 
  bool check=1; 
  do{
   
    x= eq->step(x,t,h,oam); 
    t=t+h; 
    if(j==g){
      if(k< 700000){
        graph_x_t.SetPoint(k,t,x[0]); 
      }else if(check==1){
        cout << "Maximum number of points reached. Graphing with 500000 points" << endl; 
        check=0; 
      }
    }
    k++; 
  } while(t <70);

  if(j==g){
    string graph_print = "graph/passo_" + to_string(h) + ".pdf"; 
    cg.cd();
    cg.SetGrid(); 
    graph_x_t.GetXaxis()->SetTitle("Tempo [s]");
    graph_x_t.GetYaxis()->SetTitle("Posizione x [m]");
    graph_x_t.Draw("AL");
    cg.SaveAs(graph_print.c_str()); 
    g=g*5;
  }
  
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
  graph_err.SetTitle("Errore commesso col metodo di Eulero in funzione del passo h"); 
  graph_err.GetXaxis()->SetTitle("h");
  graph_err.GetYaxis()->SetTitle("#Delta x [m]");
  graph_err.Draw("AL*");

  e.SaveAs("graph_err.pdf");

  cout << "I plot relativi agli h considerati nel grafico si trovano nella cartella <graph>" << endl; 

  myApp.Run();




return 0; 
}
