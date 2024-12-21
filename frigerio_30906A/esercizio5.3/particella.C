#include"particella.h"
#include <iostream> 

using namespace std;
particella::particella(double mp,double qp){
    m=mp;
    q=qp;
}

void particella::print_p(){
    cout << "Particella || m : " << getm() << " kg | q : " << getq() << " C" << endl;
}


void elettrone::print_p(){
    cout << "Elettrone || m : " << getm() << " kg | q : " << getq() << " C" << endl;
}