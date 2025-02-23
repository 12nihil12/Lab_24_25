#include "vec_doub.h"

//CONSTRUCTORS 
vec_doub::vec_doub()
{
    ad = NULL; 
    dim=0; 
}

vec_doub::vec_doub(int N) 
{
    if(N>0){
        dim=N; 
        ad = new double [dim]; 
        for (int c=0; c< dim; c++){
            ad[c]=0;
        }
    } else { 
        cout <<"Impossibile creare un array di" << N << " <= 0 elementi" << endl; 
        throw 1; // errorcode: dimension < =0
    }
}

vec_doub::vec_doub(const vec_doub& w){ //copy constructor
    dim=w.getdim();
    used=w.getused();
    ad= new double [dim]; 
    for(int i=0; i < dim; i++){
        ad[i]=w[i]; 
    }
}

//DESTRUCTOR

vec_doub::~vec_doub()
{
    delete [] ad;
    ad=NULL; 
}


// OPERATORS

vec_doub& vec_doub::operator=(const vec_doub& w){//assignment operator
    dim=w.getdim(); 
    if(ad){
        delete [] ad; 
    }
    ad= new double[dim];

    for(int i=0; i < dim; i++){
        ad[i]=w[i]; 

    }

    return *this;
} 

double& vec_doub::operator[](int i){
    if(i >=0 && i < dim){
        return ad[i];
    } else{
        throw 2; // errorcode : index over range
    }
}

double & vec_doub::operator[](int i) const{
    if(i >=0 && i < dim){
        return ad[i];
    } else{
        throw 2; // errorcode : index over range
    }
} 

bool vec_doub::operator==(const vec_doub & w)const {
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





//ACCESS 



/* 
int vec_doub::setcomponent(int i,double el){
    if(i < 0 || i >= dim){
        throw 2; // errorcode : index over range
    }
    ad[i]=el; 
    return 0; 
}; //modify  i component
  
  
double vec_doub::getcomponent(int i) const {
        if(i < 0 || i >= dim){
        throw 2; // errorcode : index over range
        } else{
            return ad[i];
        }
}; // access to i component

*/

