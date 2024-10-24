#include"particella.h"
#include <iostream> 

using namespace std;
particella::particella(double mp,double qp){
    m=mp;
    q=qp;
}

void particella::print(){
    cout << "Particella || m : " << getm() << " kg | q : " << getq() << " C" << endl;
}


void elettrone::print(){
    cout << "elettrone || m : " << getm() << " kg | q : " << getq() << " C" << endl;
}