#ifndef vec_h
#define vec_h

#include <iostream>
#include <exception>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std; 


template <typename T> class vec
{
    public:
    //CONSTRUCTORS 
        vec(); // void costructor
        vec(int N); //costructor given dimension
        vec(const vec<T>&); // copy constructor
        vec(int N, char * filename);// constructor from file


    //DESTRUCTOR
        ~vec(); 

    //OPERATORS
        vec& operator=(const vec<T>&); //assignment operator
        T& operator[](int i); //access component operator
        T& operator[](int i) const; //access component operator const
        bool operator==(const vec<T> &) const; 
        
    
    //ACCESS
        int getdim() const {return dim;}// access to vector dimension
        T * getad() const {return ad;} //access to vector address
        //int setcomponent(int,T); //modify to i component
        //T getcomponent(int) const; // access to i component

    //ORDERING
        int posmin (int i); //restituisce posizione elemento minimo array a partire da i
        void swap(int i, int j); // swap elementi 
        void order();//ordinamento array 

    //PRINT 
        void print(char* nomefile) const ;
        void print() const ;


    
    private: 
        int dim; //dimension
        T * ad; //vector
};




//IMPLEMENTAZIONE

//CONSTRUCTORS 
template <typename T> vec<T>::vec()
{
    ad = NULL; 
    dim=0; 
}

template <typename T> vec<T>::vec(int N) 
{
    if(N>0){
        dim=N; 
        ad = new T [dim]; 
        for (int c=0; c< dim; c++){
            ad[c]=0;
        }
    } else {
        throw 1; // errorcode: dimension < 0
    }
}

template <typename T> vec<T>::vec(const vec<T> & w){ //copy constructor
    dim=w.getdim();
    ad= new T [dim]; 
    for(int i=0; i < dim; i++){
        ad[i]=w[i]; 
    }
}


template <typename T> vec<T>::vec(int N, char * filename){

    dim= N; 
    ad= new T [dim]; 

    ifstream filein; 
    filein.open(filename);

    if(filein.fail()){
        cout << "File " << filename << " not found" << endl; 
        throw -1; //something happened, sorry no idea
    }

    

   
    
    for(int c=0; c < dim; c++){
        filein >> ad[c];
    }


}

//DESTRUCTOR

template <typename T> vec<T>::~vec()
{
    delete [] ad;
    ad=NULL; 
}


// OPERATORS

template <typename T> vec<T>& vec<T>::operator=(const vec<T>& w){//assignment operator
    dim=w.getdim(); 
    if(ad){
        delete [] ad; 
    }
    ad= new T[dim];

    for(int i=0; i < dim; i++){
        ad[i]=w[i]; 

    }

    return *this;
} 

template <typename T> T& vec<T>::operator[](int i){
    if(i >=0 && i < dim){
        return ad[i];
    } else{
        throw 2; // errorcode : index over range
    }
}

template <typename T> T & vec<T>::operator[](int i) const{
    if(i >=0 && i < dim){
        return ad[i];
    } else{
        throw 2; // errorcode : index over range
    }
} 

template <typename T> bool vec<T>::operator==(const vec<T> & w)const {
    if(dim != w.getdim()){
        return false;
    }
    for(int i=0; i< dim; i++){
        if(ad[i]!= w[i]){
            return false;
        }
    }
    return true; 
    
}



//ORDERING

template <typename T> int vec<T>::posmin ( int i){ 
    int pmin = i;   
    for (int c=i; c < dim; c++){
        if(ad[c] < ad[pmin]){
            pmin = c; 
        }

    }
    
    return pmin; 
}

template <typename T> void vec<T>::swap(int i, int j){ // swap elementi T
    if (i < 0 || i > dim || j < 0 || j > dim){
        throw 2; //index out of range
    }
    T jolly = ad[i]; 
    ad[i]= ad[j]; 
    ad[j]= jolly; 
    
    return; 
}


template <typename T> void vec<T>::order(){ //ordinamento array T
    for (int k = 0; k < dim -1; k++){
        int min = posmin(k);
        try{
            swap(k, min);
        }
        catch (...){
            throw -1;
        }
    }
    
    return; 
}



//PRINT

template <typename T> void vec<T>::print(char* nomefile) const {
    ofstream fileout; 
    fileout.open(nomefile); 
    for(int c=0; c< getdim(); c++){
        fileout << getad()[c] << endl;
    }
    fileout.close();
}
template <typename T> void vec<T>::print( ) const{
      for(int c=0; c< getdim(); c++){
        cout << getad()[c] << endl;
    }
    
}

//ACCESS 



/* 
int template <typename T> vec<T>::setcomponent(int i,T el){
    if(i < 0 || i >= dim){
        throw 2; // errorcode : index over range
    }
    ad[i]=el; 
    return 0; 
}; //modify  i component
  
  
T template <typename T> vec<T>::getcomponent(int i) const {
        if(i < 0 || i >= dim){
        throw 2; // errorcode : index over range
        } else{
            return ad[i];
        }
}; // access to i component

*/





#endif