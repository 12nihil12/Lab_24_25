#ifndef fun_vet_base_h
#define fun_vet_base_h

#include <cmath> 
#include<vector> 
#include "vector_operation.h"

#define G 6.6742E-11 
#define M_S 1.9884E+30
#define A 147098074E+3
#define V 30.287E+3

class fun_vet_base{
    public:
    fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x) const =0; 
       

};



 class terra:public fun_vet_base{
    public:
        terra(): fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 
    
            double r=sqrt(pow(x[0],2) + pow(x[2],2)); 
            F[0]=x[1];
            F[1]=-G*M_S*x[0]/pow(r,3); 
            F[2]= x[3]; 
            F[3]=-G*M_S*x[2]/pow(r,3);  
            return F; 
        }


    
};


/* VERSIONE IN COORDINATE POLARI
class terra:public fun_vet_base{
    public:
        terra(): fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 
    
        
            F[0]=x[1];
            F[1]=(V*V*A*A)/pow(x[0],3) - (G*M_S)/pow(x[0],2); 
            F[2]=(V*A)/(pow(x[0],2));  
            return F; 
        }


    
};
 */


 class rosetta:public fun_vet_base{
    public:
        rosetta(): fun_vet_base() { ;}; 
        virtual vector <double>  eval(double t, const vector <double> &x)const override{

            vector <double> F(x.size()); 
    
            double r=sqrt(pow(x[0],2) + pow(x[2],2)); 
            F[0]=x[1];
            F[1]=-G*M_S*x[0]/pow(r,3) + 10E30*x[0]/pow(r,4) ; 
            F[2]= x[3]; 
            F[3]=-G*M_S*x[2]/pow(r,3)+10E30*x[2]/pow(r,4);  
            return F; 
        }


    
};

#endif