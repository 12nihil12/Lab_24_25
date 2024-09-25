#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "functions.h"

using namespace std; 

int main(int argc,char ** argv)
{
    
    if(argc<3){
        cout << "Syntax: <ndati> <filename>" << endl; 
        return -1;
    }
    int ndt=stoi(argv[1]);
    cout << "Numero dati: " << ndt << endl; 
    char * nomefile= argv[2];
    cout << "Nome file: " << nomefile << endl << endl; 

    double *v; 
    v= new double [ndt]; 
   
    int check=loaddata(nomefile,v,ndt);
    if(check !=0){
        return -1;
    }
    
    ofstream fileout; 
    fileout.open("Results.txt"); 

    double med=media(v,ndt);
    cout<< "Media: " << med << endl; 
    fileout << "Media: " << med << endl; 

    double var = varianza(v,ndt,med); 
        cout<< "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    fileout << "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
     double median = mediana(v,ndt); 
        cout<< "Mediana: " << median << endl; 
    fileout << "Mediana: " << median << endl; 

    //cout << "Array ordinato: " << endl << endl; 

   // print(v,ndt);
    print("1941_data_reorder.txt",v,ndt);

    
   return 0;
   
}