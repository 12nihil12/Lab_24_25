#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 

#include"fun.h"
#include "integrator.h"
#include "int_fun.h"
#include "solver.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;
int main(int argc, char** argv) {

  
    TApplication myApp("myApp",0,0);
    
    auto * f= new myfun(450e-9); 
    double d=100e-6; 
    auto * i_t = new trapezi(-d/2,d/2);

    TGraph g; 
    double x=-0.10; 
    int k=0;
    double epsilon=1e-4; 
    double A; 

    do{
        f->set_x(x); 
        A=i_t->calc(f,epsilon); 
        //cout << x  << " " << A << endl; 
        g.SetPoint(k,x,A); 
        x=x+0.001; 
        
        k++;
    }while(x<0.1); 
    


    TCanvas c; 
    c.cd(); 
    c.SetGrid(); 
    g.SetMarkerStyle(20); 
    g.SetMarkerColor(kBlue); 

    g.Draw("ALP");
    g.GetXaxis()->SetTitle("x[m]"); 
    g.GetYaxis()->SetTitle("A (x) [m]"); 




    auto * f2= new myfun2(500e-9); 
   

    auto * sol= new bisezione(); 


    double zero=sol->find_zero(0,0.05,f2,1e-6); 

    cout << "lambda = 500 nm | A(x)= 0 -> |x|= " << fixed << setprecision(6) <<  zero <<  " m "<< endl;

    f2->set_l(400e-9); 

    zero=sol->find_zero(0,0.05,f2,1e-6); 

    cout << "lambda = 400 nm | A(x)= 0 -> |x|= " << fixed << setprecision(6) <<  zero <<  " m " << endl;

    f2->set_l(450e-9); 


    zero=sol->find_zero(0,0.05,f2,1e-6); 

    cout << "lambda = 450 nm | A(x)= 0 -> |x|= " << fixed << setprecision(6) <<  zero <<  " m "  << endl;


    myApp.Run();
    

   
    return 0; 
}

