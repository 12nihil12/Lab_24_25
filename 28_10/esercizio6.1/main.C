#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 

#include"fun.h"

using namespace std;

int main(int argc, char** argv) {

auto *p = new parabola(3,5,-2); 



cout << p->eval(-p->getb()/(2*p->geta())) << endl; 


return 0; 
}