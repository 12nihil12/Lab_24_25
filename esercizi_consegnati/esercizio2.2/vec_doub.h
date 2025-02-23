#ifndef vec_doub_h
#define vec_doub_h

#include <iostream>
#include <exception>
#include <cmath>

using namespace std; 

class vec_doub
{
    public:
    //CONSTRUCTORS 
        vec_doub(); // void costructor
        vec_doub(int N); //costructor given dimension
        vec_doub(const vec_doub&); // copy constructor

    //DESTRUCTOR
        ~vec_doub(); 

    //OPERATORS
        vec_doub& operator=(const vec_doub&); //assignment operator
        double& operator[](int i); //access component operator
        double & operator[](int i) const; //access component operator const
        bool operator==(const vec_doub &) const; 
    

    
    //ACCESS
        unsigned int getdim() const {return dim;}// access to vector dimension
        double * getad() const {return ad;} //access to vector address
        void setused(unsigned int k) {used=k;};
        unsigned int getused() const {return used;}; 

    
    private: 
        unsigned int dim; //dimension
        double * ad; //vector
        unsigned int used; // quanti valori sono effettivamente usati (per riempimento da file)
};





#endif