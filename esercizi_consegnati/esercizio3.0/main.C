#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "vec.h"
#include "stat.h"

using namespace std; 

int main(int argc,char ** argv)
{
    
    if(argc!=3){
        cout << "Uso di " << argv[0] << ": <ndati> <nome file>" << endl; 
        return -1;
    }
    
    
    int ndt=stoi(argv[1]);
    cout << "Dimensione del dataset: " << ndt << endl; 
    char * nomefile= argv[2];
    cout << "Nome file: " << nomefile << endl << endl; 



    vec <double>* v; 


    try{
        v=new vec<double>(ndt,nomefile); 
    }
    catch(...){
        return -1; //se il file non è stato trovato o la dimensione inserita è <= 0, chiude il programma
    }

    


    ofstream fileout; 
    fileout.open("Risultati.txt"); 

    double med=  media<double>(*v);
    cout<< "Media: " << med << endl; 
    fileout << "Media: " << med << endl; 

    double var = varianza<double> (*v,med); 
    cout<< "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    fileout << "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    
    
    double median =mediana<double>(*v); 
    cout<< "Mediana: " << median << endl; 
    fileout << "Mediana: " << median << endl; 
    

    
   return 0;
   
}