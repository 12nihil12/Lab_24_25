#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include "vec.h"
#include "stat.h"

using namespace std; 

int main(int argc,char ** argv)
{
    
    if(argc<3){
        cout << "Syntax: <ndati> <filename>" << endl; 
        return -1;
    }
    int ndt=stoi(argv[1]);
    while (ndt < 0)
    {
        cout << "Negative dimension of dataset is not allowed. Please enter valid dimension." << endl; 
        cin >> ndt; 
    }

    cout << "Dimension of dataset: " << ndt << endl; 
    
    char * nomefile= argv[2];
    cout << "File name: " << nomefile << endl << endl; 



    vec <double> v(ndt,nomefile);
    
    
    ofstream fileout; 
    fileout.open("Results.txt"); 

    double med=  media<double>(v);
    cout<< "Media: " << med << endl; 
    fileout << "Media: " << med << endl; 

    double var = varianza<double> (v,med); 
        cout<< "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
    fileout << "Varianza: " << var << " e dev. std: " << sqrt(var) << endl; 
     double median =mediana<double>(v); 
        cout<< "Mediana: " << median << endl; 
    fileout << "Mediana: " << median << endl; 

    //cout << "Array ordinato: " << endl << endl; 

   // print(v,ndt);
    

    
   return 0;
   
}