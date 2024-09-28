#ifndef vec_doub_h
#define vec_doub_h

#include <iostream>
#include <exception>

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
    
    //ACCESS
        int getdim() const {return dim;}// access to vector dimension
        double * getad() const {return ad;} //access to vector address
        int setcomponent(int,double); //modify to i component
        double getcomponent(int) const; // access to i component

    private: 
    int dim; //dimension
    double * ad; //vector
};





#endif