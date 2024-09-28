#include <iostream>
#include <cstdlib>
#include <exception>
#include"vec_doub.h"

using namespace std; 

int main (int argc, char ** argv){

    int N=stoi(argv[1]);


    vec_doub v(N); 
    for(int i=0; i < v.getdim(); i++){
        v.setcomponent(i,i); 
    }

    
    
    return 0; 

}