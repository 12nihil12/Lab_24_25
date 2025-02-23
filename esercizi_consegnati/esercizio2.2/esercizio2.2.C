#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "functions.h"
#include "vec_doub.h"

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




    
    vec_doub * v; 




    try{
        v=new vec_doub(ndt); 
    }
    catch(...){
        return -1;
    }

    v->setused(ndt);
    


   
    try{
        loaddata(nomefile,*v); 
    }
    catch (int e){
        if(e==-1) return -1; //se il file non è stato trovato, chiude il programma
        else v->setused(e); // altrimenti salva il numero effettivo di dati caricati tra i data membri di v
    }

   


    ofstream fileout; 
    fileout.open("Risultati.txt"); 

    double med=media(*v);
    cout<< "Media: " << med << endl; 
    fileout << "Media: " << med << endl; 

    double var = varianza(*v,med); 
    cout<< "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    fileout << "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
   
    double median = mediana(*v); 
    cout<< "Mediana: " << median << endl; 
    fileout << "Mediana: " << median << endl; 

  

    
   return 0;
   
}