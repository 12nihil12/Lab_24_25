#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 

#include"fun.h"
#include "solver.h"
using namespace std;

int main(int argc, char** argv) {
auto *p = new parabola(3,5,-2); 


auto * s = new bisezione(); 

double zero= s->find_zero(-1,1,p,0.0001)  ; //Per qualche motivo non accetta l'omissione dell'argomento opzionale

cout << setprecision(-log10(s->Getprec())) << zero << endl; 


return 0; 
}