#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 

#include "particella.h"



using namespace std;

int main(int argc, char** argv) {

     particella *p = new particella(1.,2.);
  elettrone  *e = new elettrone();
  particella *b = new elettrone(); // Puntatore a particella che punta ad un oggetto elettrone

  p->print_p(); // Metodo print_p di particella
  e->print_p(); // Metodo print_p di elettrone
  b->print_p(); // Quale print_p ???

  delete p;
  delete e;
  delete b;

return 0; 
}