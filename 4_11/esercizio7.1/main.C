#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include <fstream> 

#include"fun.h"
#include "integrator.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"


using namespace std;

int main(int argc, char** argv) {

    unsigned int N; 

    if(argc != 2){
        cout << "Usage of " << argv[0] << " : <number of intervals>" << endl; 
        return 0; 
    }

    TApplication app("app",0,0);

    auto *f= new myfun(); 
    ofstream file_out; 
    file_out.open("err_table.txt"); 
    N=atoi(argv[1]);

    double a =0; 
    double b= M_PI/2;


    //auto * i_MP = new midpoint(0, M_PI/2); 
    auto * i_S = new simpson(a,b); 

    //cout << i_MP->calc(f,N) << endl;
    //cout << i_S->calc(f,N) << endl;


    TGraph g; 

    double err,h;

    TCanvas c("Err","Err");

    for(int i= 1; i <= N; i++ ){
        int s=2*i; 
        h=(b-a)/s; 
        err=fabs(1-i_S->calc(f,s)); 
        file_out << "Step: " << s << "| h: " << h << " |  error: " << err << " | integrale " << i_S->get_int() << endl; 
        g.SetPoint(i-1,s,err); 
    }

    cout << "Integral value with " << N << " steps : " << i_S->get_int() << endl; 
    c.SetLogy();
    c.SetLogx();

    c.SetGrid();
    g.Draw("A*");
    g.GetXaxis()->SetTitle("lg(N)");
    g.GetYaxis()->SetTitle("lg(err)");

   
    g.SetTitle("Andamento della discrepanza tra il valore vero e il valore calcolato (err) all'aumentare del numero di intervalli N");

    c.SaveAs("graph_err.pdf");

    
    app.Run();
    return 0; 
}