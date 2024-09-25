
#include "functions.h"

void print(char* nomefile, double * v, int ndt){
    ofstream fileout; 
    fileout.open(nomefile); 
      for(int c=0; c< ndt; c++){
        fileout << v[c] << endl;
    }
    fileout.close();
}
void print( double * v, int ndt){
    ; 
      for(int c=0; c< ndt; c++){
        cout << v[c] << endl;
    }
    
}

int loaddata(char * nomefile, double * v,int ndt){

    ifstream filein(nomefile); 

    if(filein.fail()){
        cout << "File " << nomefile << " not found" << endl; 
        return -1; 
    }
    
    for(int c=0; c< ndt; c++){
        filein >> v[c];
    }


    return 0;
}



int posmin (double v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int pmin = i;   
    for (int c=i; c < size; c++){
        if(v[c] < v[pmin]){
            pmin = c; 
        }

    }
    
    return pmin; 
}

void swap(double v[], int i, int j, int size){ // swap elementi double
    if (i < 0 || i > size || j < 0 || j > size){
        cout << "Indici fuori range" << endl; 
        return; 
    }
    double jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}

void order(double v[], int size){ //ordinamento array double
    for (int k = 0; k < size -1; k++){
        //cout << "k=" << k; 
        int min = posmin(v, k, size);
        //cout << "min: " << A[j]; 
        swap(v, k, min, size);
        //cout << "scambio " << A[k] <<endl; 
    }
    
}


//STAT


double mediana (double v[], int size){

    order(v, size); 
    
 if(size%2==0){
        return (double)(v[size/2 -1 ]+v[size/2 ])/2;
    } else {
        return (double)v[(size+1)/2 -1]; 
    }
}

double media (double v[], int ndt){

    double conta = 0; 


    for( int c= 0; c < ndt; c++){
        conta= conta*c/(c+1) + v[c]/(c+1);
    }

    //double media = conta / ndt; 
    return conta; 
}



double varianza (double v[], int ndt, double x) { // varianza (avendo gia` la media)

    double scarto = 0;

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    return scarto/ndt; 
}
