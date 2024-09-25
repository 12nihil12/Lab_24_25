#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 

using namespace std; 

void print(char* nomefile, double * v, int ndt); // print array su file
void print( double * v, int ndt); // print array a video
int loaddata(char * nomefile, double * v,int ndt); // carica dati da file su array


int posmin (double v[], int i, int size); //restituisce posizione elemento minimo array di (size) elementi a partire da i
void swap(double v[], int i, int j, int size); // swap elementi double
void order(double v[], int size);//ordinamento array double


double mediana (double v[], int size);
double media (double v[], int ndt);
double varianza (double v[], int ndt, double x); // varianza (avendo gia` la media)

#endif