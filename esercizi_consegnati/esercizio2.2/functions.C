
#include "functions.h"

void print(char* nomefile, const vec_doub& v){
    ofstream fileout; 
    fileout.open(nomefile); 
    for(int c=0; c< v.getused(); c++){
        fileout << v[c] << endl;
    }
    fileout.close();
}
void print( const vec_doub& v){
      for(int c=0; c< v.getused(); c++){
        cout << v[c] << endl;
    }
    
}

void loaddata(char * nomefile, vec_doub& v){

    ifstream filein(nomefile); 

    if(filein.fail()){
        cout << "File " << nomefile << " not trovato" << endl; 
        throw -1; 
    }
    
    for(int c=0; c < v.getdim(); c++){
        filein >> v[c];

        if(filein.eof()){
            cout << "Si è raggiunta la fine del file: conteneva " << c << " dati" << endl; 
            throw c; // passa il numero di dati contenuti nel file
        }
    }


    return; 
}



int posmin (vec_doub  v, int i){ //restituisce posizione elemento minimo array di (v.getused()) elementi a partire da i
    int pmin = i;  
    for (int c=i; c < v.getused(); c++){
        if(v[c] < v[pmin]){
            pmin = c; 
        }

    }
    
    return pmin; 
}

void swap(vec_doub & v, int i, int j){ // swap elementi double
    if (i < 0 || i > v.getused() || j < 0 || j > v.getused()){
        cout << "Index out of range" << endl; 
        return; 
    }
    double jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}

void order(vec_doub & v){ //ordinamento array
    for (int k = 0; k < v.getused()-1; k++){
        int min = posmin(v, k);
        swap(v, k, min);
        
    }
    
}


//STATISTICA


double mediana (vec_doub v){
    order(v); 
    print("1941_riordino_dati_txt",v);
    if(v.getused()%2==0){
        return (double)(v[v.getused()/2 -1 ]+v[v.getused()/2 ])/2;
    } else {
        return (double)v[(v.getused()+1)/2 -1]; 
    }
}

double media (const vec_doub & v){
    double conta = 0; 
    for( int c= 0; c < v.getused(); c++){
        conta= conta*c/(c+1) + v[c]/(c+1);
    }

    return conta; 
}



double varianza (const vec_doub & v , double x) { // varianza (avendo gia` la media)

    double scarto = 0;

     for( int c= 0; c < v.getused(); c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }

    return scarto/v.getused(); 
}
