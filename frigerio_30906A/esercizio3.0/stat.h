#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "vec.h"

using namespace std; 



template <typename T> double mediana (vec<T> v);

template <typename T>  double media (const vec<T>& v);

template <typename T> double varianza (const vec<T> & v, double x); // varianza (avendo gia` la media)





template <typename T> double mediana (vec<T> v){
    v.order(); 
    v.print("1941_riordino_dati.txt");
    if(v.getused()%2==0){
        return (double)(v[v.getused()/2 -1 ]+v[v.getused()/2 ])/2;
    } else {
        return (double)v[(v.getused()+1)/2 -1]; 
    }
}


template <typename T> double media (const vec<T> & v){

    double conta = 0; 
    for( int c= 0; c < v.getused(); c++){
        conta= conta*c/(c+1) + (double)v[c]/(c+1);
    }

    return conta; 
}




template <typename T> double varianza (const vec<T> & v , double x) { // varianza (avendo gia` la media)

    double scarto = 0;

     for( int c= 0; c < v.getused(); c++){
        scarto = scarto + pow((x - (double)v[c]), 2); 
    }

    return scarto/v.getused(); 
}

#endif