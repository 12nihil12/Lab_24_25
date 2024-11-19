
#pragma once 
#include  <vector> 
#include <exception> 
#include <fstream>
#include <iostream>

using namespace std; 


template <typename T> inline void print(const char * nomefile, vector<T> v) {
    ofstream fileout; 
    fileout.open(nomefile); 
    fileout << "["; 
    for(int c=0; c< v.size()-1; c++){
        fileout << v[c] << ","; 
    }
     fileout << v[v.size()];
    fileout << "]"<< endl; 
    fileout.close();
}

template <typename T> inline  void print(vector<T> v) {
    cout << "["; 
        for(int c=0; c< v.size()-1; c++){
        cout << v[c] << ","; 
    }
    cout << v[v.size()-1];
    cout << "]"<< endl; 

}


template <typename T> inline vector<T> operator+ (const vector<T> &a , const vector<T> &b){
    if(a.size() != b.size()){
        cout << "Sum of vectors of different sizes is not allowed." << endl; 
        throw 13; 
    }
    vector<T> result(a.size());
    for(int i=0; i < int(a.size()); i++){
        result[i]= a[i]+b[i]; 
    }
    return result; 
}


template <typename T> inline T operator* (const vector<T> &a , const vector<T> &b){
    if(a.size() != b.size()){
        cout << "Inner product of vectors of different sizes is not allowed." << endl; 
        throw 13; 
    }
    T sum=0; 
    for(int i=0; i < int(a.size()); i++){
        sum=sum + a[i]*b[i]; 
    }
    return sum;
}


template <typename T> inline vector<T> operator* (const vector<T> &a ,T l){
    vector<T> result(a.size());
    for(int i=0; i < int(a.size()); i++){
        result[i]=a[i]*l; 
    }

    return result; 
}



template <typename T> inline vector<T> operator* (T l, const vector<T> &a ){
    vector<T> result(a.size());
    for(int i=0; i < int( a.size()); i++){
        result[i]= a[i]*l; 
    }
    return result; 
}


