#ifndef in_out_h
#define in_out_h

#include <iostream>
#include <fstream> 
#include <exception> 
#include <vector> 

using namespace std; 


template <typename T> vector<T> loadff(char * filename); 
template <typename T>  void print(char* nomefile, vector<T> v); 
template <typename T>  void print(vector<T> v); 

template <typename T> vector<T> loadff(char * filename){

    ifstream filein; 
    filein.open(filename);
    if(filein.fail()){
        cout << "File " << filename << " not found" << endl; 
        throw -1; //something happened, sorry no idea
    }
    vector<T> v; 

    while(!filein.eof()){
        T appo; 
        filein>> appo; 
        v.push_back(appo);
    }
    
    return v; 
}

template <typename T>  void print(char* nomefile, vector<T> v) {
    ofstream fileout; 
    fileout.open(nomefile); 
    for(int c=0; c< v.size(); c++){
        fileout << v[c] << endl;
    }
    fileout.close();
}

template <typename T>  void print(vector<T> v) {
        for(int c=0; c< v.size(); c++){
        cout << v[c] << endl;
    }
}

#endif