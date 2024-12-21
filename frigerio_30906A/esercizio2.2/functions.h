#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "vec_doub.h"

using namespace std; 


//STAMPA E RIEMPIMENTO ARRAY

void print(char* nomefile, const vec_doub & v); // stampa array su file
void print(const vec_doub& v); // stampa array a video
void loaddata(char * nomefile, vec_doub &v); // carica ndt dati da <nomefile> e li salva nell'array v


//ORDINAMENTO

int posmin (vec_doub v, int i); //restituisce posizione elemento minimo array di (size) elementi a partire da i
void swap(vec_doub & v, int i, int j); // swap elementi double
void order(vec_doub & v);//ordinamento array double

//STATISTICA
double mediana (vec_doub v);
double media (const vec_doub & v);
double varianza (const vec_doub & v, double x); // varianza (avendo gia` la media)

#endif