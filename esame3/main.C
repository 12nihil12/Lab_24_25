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
#include "TSystem.h"

#include "vector_operation.h"
#include "fun_vet_base.h"
#include "eq_diff.h"

using namespace std;



int main(int argc, char** argv) {



  TApplication myApp("myApp",0,0);

  TGraph graph_err ;

  vector <double> x_0 {1.,0.,0.,1.}; 
  vector <double> x =x_0; 


  double h=0.01;
  auto * fun = new myfun(0.); 
  auto * fun1 = new myfun(2.); 
  auto * fun2 = new myfun(-2.); 
  auto * fun3 = new myfun2(2.); 




  auto * eq = new runge_kutta(x_0,0.); 

  int k=0; 
  double t=0; 
  double err; 
  
  
    TCanvas cg; 

    TGraph g1,g2,g3,g4,g5; 
    cg.cd();
    cg.SetGrid(); 

    g1.SetTitle("#alpha=0"); 
    g1.GetXaxis()->SetTitle("x[m]");
    g1.GetYaxis()->SetTitle("y [m]");

    g2.SetTitle("#alpha=2"); 
    g2.GetXaxis()->SetTitle("x[m]");
    g2.GetYaxis()->SetTitle("y [m]");

    g3.SetTitle("#alpha=-2"); 
    g3.GetXaxis()->SetTitle("x[m]");
    g3.GetYaxis()->SetTitle("y [m]");



    g4.SetTitle("B(r)=1+ 1/r^{2}. Grafico t-r(t)");
    g4.GetXaxis()->SetTitle("t[s]");
    g4.GetYaxis()->SetTitle("r[m]");
    
    g5.SetTitle("B(r)=1+ 1/r^{2}. Grafico x(t)-y(t) (traiettoria)"); 
    g5.GetXaxis()->SetTitle("x[m]");
    g5.GetYaxis()->SetTitle("y [m]");
    
  
    g1.SetMarkerColor(kBlue);
    g1.SetMarkerStyle(20);
    g1.SetMarkerSize(0.5);

    g2.SetLineColor(kBlue);
    g2.SetMarkerColor(kBlue);
    g2.SetMarkerStyle(20);
    g2.SetMarkerSize(0.5);


    g3.SetLineColor(kBlue);
    g3.SetMarkerColor(kBlue);
    g3.SetMarkerStyle(20);
    g3.SetMarkerSize(0.5);




    g4.SetLineColor(kBlue);
    g4.SetMarkerStyle(20);
    g4.SetMarkerColor(kBlue);
    g4.SetMarkerSize(0.5);


    g5.SetLineColor(kBlue);
    g5.SetMarkerColor(kBlue);
    g5.SetMarkerStyle(20);
    g5.SetMarkerSize(0.5);


    vector <double> _x_[4]; 

      do{
    
        _x_=x; 
        x= eq->step(x,t,fun,h); 
        t=t+h; 

        g1.SetPoint(k,x[0],x[1]); 
        //cg.Update();
        //gSystem->ProcessEvents();


      

        if(_x_[1]*x_[1]<0){
          
          cout << i << endl;


        }
        
        k++; 
      } while(t <2*M_PI*10);


    
    g1.Draw("ALP");
    
    cout << x[0] << endl; 
      
    cout << "x(10T) - x(0) = " << fabs( 1.0003-1) <<endl;

    x_0[0]=1.1; 

    vector <double> x_1 =x_0; 
    vector <double> x_2 =x_0; 
    vector <double> x_3 =x_0; 



    t=0; 
    k=0; 
    do{
        x_1= eq->step(x_1,t,fun1,h);
        x_2= eq->step(x_2,t,fun2,h); 
        x_3= eq->step(x_3,t,fun3,h); 

        g2.SetPoint(k,x_1[0],x_1[1]); 
        g3.SetPoint(k,x_2[0],x_2[1]); 
        double r= sqrt(x_3[0]*x_3[0]+x_3[1]*x_3[1]);
        g4.SetPoint(k,t,r); 
        g5.SetPoint(k,x_3[0],x_3[1]); 

        t=t+h; 



        k++; 
    } while(t <M_PI*10);

  

  TCanvas e,f; 
  e.Divide(2,1); 
  f.Divide(2,1); 

  e.cd(1); 
  gPad->SetGrid();
  g2.Draw("ALP");
  e.cd(2);
  g3.Draw("ALP");
  gPad->SetGrid();
  f.cd(1); 
  g4.Draw("ALP"); 
  gPad->SetGrid();

  f.cd(2); 
  gPad->SetGrid();
  g5.Draw("ALP"); 

  cout << "Per a=2 il moto diverge. Per a=-2 rimane confinato." << endl; 
  cout << "Con B(r)=1/r^2 +1, il raggio oscilla tra due valori e si ha un moto a rosetta" << endl; 

  //cg.SaveAs("1.pdf"); 
  //e.SaveAs("2.pdf"); 
  //f.SaveAs("3.pdf"); 




  myApp.Run();




  return 0; 
}
