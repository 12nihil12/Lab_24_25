#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "vec_doub.h"

using namespace std; 

void print(char* nomefile, const vec_doub & v); // prints array on file
void print(const vec_doub& v); // prints array on screen
int loaddata(char * nomefile, vec_doub &v); // loads data from file to vec


int posmin (vec_doub v, int i); //restituisce posizione elemento minimo array di (size) elementi a partire da i
void swap(vec_doub v, int i, int j); // swap elementi double
void order(vec_doub v);//ordinamento array double


double mediana (vec_doub v);
double media (const vec_doub & v);
double varianza (const vec_doub & v, double x); // varianza (avendo gia` la media)

#endif