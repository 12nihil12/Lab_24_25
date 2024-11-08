#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <exception> 
#include"fun.h"
#include "integrator.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;

int main(int argc, char** argv) {


    double epsilon; 

    cout << "What precision do you need?" << endl; 
    cin >> epsilon; 

    double a =0; 
    double b= M_PI/2;

    auto * f= new myfun(); 
    auto * i_t = new trapezi(a,b);
 

    cout << "Integral: " << i_t->calc(f,epsilon) << endl << endl; 

    

    /*

    unsigned int N=i_t->get_N(); 
    cout << "Integrale a N fissato, metodo dei trapezi" << endl; 
    unsigned int i=1; 
    int k=1; 
    do{
        i= pow(2,k); 
        cout << i <<  "| " << i_t->calc(f,2*i) << endl; 

        k++; 
    }while(i < N); 

    */

    return 0; 
}