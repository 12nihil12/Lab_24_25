#pragma once

#include <cmath> 
#include <iostream> 
#include <exception>



using namespace std; 


bool check(){
    char ans; 
    cout << "Attenzione: questa azione può causare un comportamento indesiderato. Continuare? [Y/n]" << endl; 
    cin >> ans; 
    if(ans=='Y' || ans=='y'){
        return 1;
    }else{
        return 0; 
    }

}

class gen_rand{
    public: 


        gen_rand(unsigned int seed){ i_seed=seed; i_a=1664525; i_c=1013904223; i_m=pow(2,31); }

    
        void SetA(unsigned int a) { if(!check()){return;} ; i_a=a;}
        void SetC(unsigned int c) { if(!check()){return;} ; i_c=c;}
        void SetM(unsigned int m) { if(!check()){return;} ; i_m=m;}

        double rand(){i_seed=(i_a*i_seed + i_c)%i_m; return double((i_a*i_seed + i_c)%i_m)/i_m; }; 
        double unif (double a, double b); 
        double esp(double l);
        double gauss(double med, double s); 
        double AR (double med, double s);  
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
        if( N>10000){
            cout << "Numero massimo di tentativi raggiunto."<< endl;
            throw 13;
        }
    }while(y>f); 
    
    return x; 
}