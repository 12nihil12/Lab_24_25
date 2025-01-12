#ifndef fun_h
#define fun_h

#include <cmath> 

class fun{
    public:
        virtual double eval(double x) const =0; 
        int sign(double x){
           if(eval(x)==0){return 0;} 
           else if (eval(x)>0){return 1;} 
           else{return -1;};
        }

};


class myfun:public fun{
    public:
        virtual double eval(double x)const override {return pow(x,3)* log(sqrt(M_E+x*x));}


};

class myfun2:public fun{
    public:
        virtual double eval(double x)const override {return 1/sqrt(4-x*x);}


};




#endif