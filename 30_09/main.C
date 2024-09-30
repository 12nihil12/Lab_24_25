#include <iostream>
#include <cstdlib>
#include <exception>
#include"vec_doub.h"

using namespace std; 

int main (int argc, char ** argv){

    int N=stoi(argv[1]);


    vec_doub v(N); 
    vec_doub w(N); 
    for(int i=0; i < v.getdim(); i++){
        v[i]=9; 
    }
    cout << "hi";
    for(int i=0; i < v.getdim(); i++){
        cout << v[i]<< endl; 
        cout << w[i]<< endl; 
    }

     try{
    
        w[2]=9;
    }
    catch (...){
        cout << "wtf";
        return -1; 
    }

    cout << "Norm: " <<  v.norm() << endl;
    cout << "Norm: " <<  w.norm() << endl;

    if(v>w){
        cout << "Yes" << endl; 
    }else{
        cout << "No" << endl; 
    }
    
    return 0; 

}