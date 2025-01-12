#pragma once

#include "integrator.h"
#include "fun.h"


/* 
 
class myfun2{



    public:
        myfun2(double l):i_l(l){;}; 
        void set_l(double l){i_l=l;}; 

        
        double eval(double x)const {
            auto * f= new myfun(i_l); 
            auto * i_t = new trapezi(-50e-6,50e-6);
            f->set_x(x);
            double epsilon=1e-4; 
            return i_t->calc(f,epsilon); 
        }

        int sign(double x){
           if(eval(x)==0){return 0;} 
           else if (eval(x)>0){return 1;} 
           else{return -1;};
        }



    private: 
        double i_l; 

   
};

*/

class myfun2{

    public:
        myfun2(double l):i_l(l) {i_t=new trapezi(-50e-6/2,50e-6);}; 
        ~myfun2(){delete i_t; }; 

        void set_l(double l){i_l=l;}; 

        
        double eval(double x){
            auto * f= new myfun(i_l); 
            f->set_x(x);
            double epsilon=1e-4;
           
            return i_t->calc(f,epsilon);
        }

        int sign(double x){
           if(eval(x)==0){return 0;} 
           else if (eval(x)>0){return 1;} 
           else{return -1;};
        }



    private: 
    
      
        trapezi * i_t; 
        double i_l; 
   
};



