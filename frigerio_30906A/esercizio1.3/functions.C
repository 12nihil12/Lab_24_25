
#include "functions.h"


//RIEMPIMENTO E STAMPA ARRAY

void print(char* nomefile, double * v, int ndt){  //stampa array su file
    ofstream fileout; 
    fileout.open(nomefile); 
    for(int c=0; c< ndt; c++){
        fileout << v[c] << endl;
    }
    fileout.close();
}
void print( double * v, int ndt){  //stampa array a video
    for(int c=0; c< ndt; c++){
        cout << v[c] << endl;
    }
}

void loaddata(char * nomefile, double * v,int ndt){ // carica ndt dati da <nomefile> e li salva nell'array v

    ifstream filein(nomefile); 

    if(filein.fail()){
        cout << "File " << nomefile << " non trovato" << endl; 
        throw -1; 
    }
    
    for(int c=0; c< ndt; c++){
        filein >> v[c];
        if(filein.eof()){
            cout << "Si è raggiunta la fine del file: conteneva " << c << " dati" << endl; 
            throw c; // passa il numero di dati contenuti nel file
        }
    }

    return; 

}


//RIORDINAMENTO

int posmin (double v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int pmin = i;   
    for (int c=i; c < size; c++){
        if(v[c] < v[pmin]){
            pmin = c; 
        }

    }
    
    return pmin; 
}

void swap(double v[], int i, int j, int size){ // swap elementi
    if (i < 0 || i > size || j < 0 || j > size){
        cout << "Indici fuori range" << endl; 
        return; 
    }
    double jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}

void order(double v[], int size){ //ordinamento array 
    for (int k = 0; k < size -1; k++){
        int min = posmin(v, k, size);
        swap(v, k, min, size);
        
    }
    
}


//STATISTICA


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

    return conta; 
}



double varianza (double v[], int ndt, double x) { // varianza (avendo gia` la media)

    double scarto = 0;

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    return scarto/ndt; 
}
