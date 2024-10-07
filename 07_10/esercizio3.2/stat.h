#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <vector> 
#include <algorithm> 
using namespace std; 



template <typename T> double mediana (vector<T> v);

template <typename T>  double media (const vector<T>& v);

template <typename T> double varianza (const vector<T> & v, double x); // varianza (avendo gia` la media)





template <typename T> double mediana (vector<T> v){
    sort(v.begin(), v.end()); 
    if(v.size()%2==0){
        return (double)(v[v.size()/2 -1 ]+v[v.size()/2 ])/2;
    } else {
        return (double)v[(v.size()+1)/2 -1]; 
    }
}


template <typename T> double media (const vector<T> & v){

    double conta = 0; 
    for( int c= 0; c < v.size(); c++){
        conta= conta*c/(c+1) + (double)v[c]/(c+1);
    }

    return conta; 
}




template <typename T> double varianza (const vector<T> & v , double x) { // varianza (avendo gia` la media)

    double scarto = 0;

     for( int c= 0; c < v.size(); c++){
        scarto = scarto + pow((x - (double)v[c]), 2); 
    }

    return scarto/v.size(); 
}

#endif