#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <exception>

#include "functions.h"
using namespace std; 

int main(int argc,char ** argv)
{
    
    if(argc!=3){
        cout << "Uso di " << argv[0] << ": <ndati> <nome file>" << endl; 
        return -1;
    }
    int ndt=stoi(argv[1]);
    cout << "Numero dati: " << ndt << endl; 
    char * nomefile= argv[2];
    cout << "Nome file: " << nomefile << endl << endl; 

    double *v; 
    v= new double [ndt]; 
   
    try{
        loaddata(nomefile,v,ndt);
    }
    catch (int e){
        if (e==-1) return -1;  // se il file non è stato trovato, chiude il programma
        else ndt= e; //setta ndt al numero effettivo di dati 
    }
    
    ofstream fileout; 
    fileout.open("Risultati.txt"); 

    double med=media(v,ndt);
    cout<< "Media: " << med << endl; 
    fileout << "Media: " << med << endl; 

    double var = varianza(v,ndt,med); 
    cout<< "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    fileout << "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
     
     
    double median = mediana(v,ndt); 
    cout<< "Mediana: " << median << endl; 
    fileout << "Mediana: " << median << endl; 

    
    print("1941_riordino_dati.txt",v,ndt);

    
   return 0;
   
}