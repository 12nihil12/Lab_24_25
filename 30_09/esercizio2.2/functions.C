
#include "functions.h"

void print(char* nomefile, const vec_doub& v){
    ofstream fileout; 
    fileout.open(nomefile); 
    for(int c=0; c< v.getdim(); c++){
        fileout << v.getcomponent(c) << endl;
    }
    fileout.close();
}
void print( const vec_doub& v){
      for(int c=0; c< v.getdim(); c++){
        cout << v.getcomponent(c) << endl;
    }
    
}

int loaddata(char * nomefile, vec_doub& v){

    ifstream filein(nomefile); 

    if(filein.fail()){
        cout << "File " << nomefile << " not found" << endl; 
        return -1; 
    }
    
    for(int c=0; c < v.getdim(); c++){
        filein >> v[c];
    }


    return 0;
}



int posmin (vec_doub v, int i){ //restituisce posizione elemento minimo array di (v.getdim()) elementi a partire da i
    int pmin = i;   
    for (int c=i; c < v.getdim(); c++){
        if(v[c] < v[pmin]){
            pmin = c; 
        }

    }
    
    return pmin; 
}

void swap(vec_doub v, int i, int j){ // swap elementi double
    if (i < 0 || i > v.getdim() || j < 0 || j > v.getdim()){
        cout << "Index out of range" << endl; 
        return; 
    }
    double jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}

void order(vec_doub v){ //ordinamento array double
    for (int k = 0; k < v.getdim() -1; k++){
        //cout << "k=" << k; 
        int min = posmin(v, k);
        //cout << "min: " << A[j]; 
        swap(v, k, min);
        //cout << "scambio " << A[k] <<endl; 
    }
    
}


//STAT


double mediana (vec_doub v){
    order(v); 

    if(v.getdim()%2==0){
        return (double)(v[v.getdim()/2 -1 ]+v[v.getdim()/2 ])/2;
    } else {
        return (double)v[(v.getdim()+1)/2 -1]; 
    }
}

double media (const vec_doub & v){

    double conta = 0; 
    for( int c= 0; c < v.getdim(); c++){
        conta= conta*c/(c+1) + v.getcomponent(c)/(c+1);
    }

    return conta; 
}



double varianza (const vec_doub & v , double x) { // varianza (avendo gia` la media)

    double scarto = 0;

     for( int c= 0; c < v.getdim(); c++){
        scarto = scarto + pow((x - v.getcomponent(c)), 2); 
    }

    return scarto/v.getdim(); 
}
