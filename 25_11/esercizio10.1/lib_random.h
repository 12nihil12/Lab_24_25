#ifndef lib_random
#define lib_random

#include <iostream>
#include <fstream> 
#include <cstdlib> 
#include <time.h> 
#include <cmath> 
#include <iomanip>

using namespace std; 

#define PI 3.14159

double randunif (double min, double max); //restituisce un valore random nell'intervallo [a,b]
double randgauss (double media, double stdv); //restituisce una variabile x appartenente ad una gaussiana a partire da una z random
void seedset (); //resetta il seed, se l'utente lo vuole


// calcolo aree 

double int_ril (int k, double a, double b, double (* f)(double x)); // calcola integrale di f(x) in [a,b]
bool is_inside (double y, double x, double (* f)(double x)); // controlla se (x,y) e' dentro l'area sottesa a f(x) 
double ril_area (int k, double a, double b,double (* f)(double x), double max, double min);//ritorna l'area della funzione f in [a, b]




#endif