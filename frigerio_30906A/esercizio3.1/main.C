#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <vector>
#include "in_out.h"
#include "stat.h" 

using namespace std; 

int main(int argc,char ** argv)
{
    
     
    if(argc!=2){
        cout << "Uso di " << argv[0] << ":  <nome file>" << endl; 
        return -1;
    }
    
    
 
    char * nomefile= argv[1];
    cout << "Nome file: " << nomefile << endl << endl; 




    

    vector <double>  v; 
    
    
    
    try{
      v=loadff<double>(nomefile); 
       
    }catch(...){
        return -1; //se il file non è stato trovato chiude il programma

    }


    
    ofstream fileout; 
    fileout.open("Risultati.txt"); 

    double med=  media<double>(v);
    cout<< "Media: " << med << endl; 
    fileout << "Media: " << med << endl; 

    double var = varianza<double> (v,med); 
        cout<< "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    fileout << "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
     double median =mediana<double>(v); 
        cout<< "Mediana: " << median << endl; 
    fileout << "Mediana: " << median << endl; 



    
   return 0;
   
}