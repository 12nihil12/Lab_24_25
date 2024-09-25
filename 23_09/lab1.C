#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 

using namespace std; 

int main(int argc,char ** argv)
{
    
    if(argc<3){
        cout << "Syntax: <ndati> <filename>" << endl; 
        return -1;
    }
    int ndt=stoi(argv[1]);
    cout << "Numero dati " << ndt << endl; 
    char * nomefile= argv[2];
    cout << nomefile << endl; 

    ifstream filein(nomefile); 

    if(filein.fail()){
        cout << "File not found" << endl; 
        return -1; 
    }
    double *v; 
    v= new double [ndt]; 
   
    for(int c=0; c< ndt; c++){
        filein >> v[c];
    }

    ofstream fileout; 
    fileout.open("check.txt"); 
      for(int c=0; c< ndt; c++){
        fileout << v[c] << endl;
    }
    fileout.close();

    double conta = 0; 


    for( int c= 0; c < ndt; c++){
        conta= conta + v[c];
    }

    double media = conta / ndt;
    fileout.open("Results.txt"); 
    cout<< "Media: " << media << endl; 
    fileout << "Media: " << media << endl; 

    double scarto = 0;
   

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((media - v[c]), 2); 
    }


    double dvstd = sqrt(scarto/ (ndt -1)); 
        cout<< "Dvst: " << dvstd << endl; 
    fileout << "Dvst: " << dvstd << endl; 
    
   return 0;
}