#pragma once

#include <cmath> 
#include <iostream> 

#define A 1664525
#define C 1013904223

using namespace std; 


inline bool check(){
    char ans; 
     cout << "Warning: this action may result in unexpected bad behavior. Continue? [Y/n]" << endl; 
    cin >> ans; 
    if(ans=='Y' || ans=='y'){
        return 1;
    }else{
        return 0; 
    }

}

class gen_rand{
    public: 


    gen_rand(unsigned int seed){ i_seed=seed; i_a=A; i_c=C; i_m=pow(2,31); }


    void SetA(unsigned int a) { if(!check()){return;} ; i_a=a;}
    void SetC(unsigned int c) { if(!check()){return;} ; i_c=c;}
    void SetM(unsigned int m) { if(!check()){return;} ; i_m=m;}

    double rand(){i_seed=(i_a*i_seed + i_c)%i_m; return double((i_a*i_seed + i_c)%i_m)/i_m; }; 
    inline double unif (double a, double b); 
    inline double esp(double l);
    inline double gauss(double med, double s); 
    inline double AR (double med, double s);  
    private: 
    unsigned int i_a,i_c,i_m,i_seed;
 


}; 

 
 double gen_rand::unif(double a, double b){


        double r= rand(); 
       


        return min(a,b) + r*fabs(a-b); 
    }

 double gen_rand::esp(double l){
        double u= rand(); 
        double v =- 1/l*log(1-u); 
        return v; 
}


 double gen_rand::gauss(double med, double s){
        double u= rand(); 
        double t= rand(); 

        double x= sqrt(-2.*log(1-u))*cos(2.*M_PI*t);
        return med+x*s; 
}

 double gen_rand::AR(double med, double s){

  

        double a = med -5*s;
        double b = med +5*s;

        double t; 
        double G= 1/(sqrt(2*M_PI)*s); 
        int N=0; 
    
        double  x; 
        double f;
        double y; 
        do{
            x=unif(a,b);
            f=G*exp(-pow((x-med),2)/(2*pow(s,2))); 
            t= rand(); 
            y=G*t;
            N++;
            if( N>1000){
                cout << "Maximum trials reached. Aborting"<< endl;
            }
        }while(y>f); 
        
        return x; 
}