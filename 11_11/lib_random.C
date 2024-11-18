#include "lib_random.h"


double randunif (double min, double max){ //valore random, probab. uniforme

    double c = (double)rand()/RAND_MAX; 
    double v =  min + c*(max-min); 
    
    return v; 
}


double randgauss (double media, double stdv){ //valore random su gaussiana 
double u1,u2, z1,z2; 
u1 = (double) rand()/RAND_MAX; 
u2 = (double) rand()/RAND_MAX;
z1 = sqrt(-2*log(u1))*cos(2*PI*u2); 
//z2 = sqrt(-2*log(u1))*sin(2*PI*u2); 

return media + z1*stdv; 

}

void seedset (){ //resetta seme 

    char check; 

    cout << "Resettare il seed? [y/n]" << endl; 
    cin >> check; 

    if(check != 'y'){
        cout << "Seed non resettato. Attenzione, ritroverà gli stessi valori casuali della precedente implementazione" << endl; 
        return; 
    }

    srand(time(NULL)); 

    cout << "Seed resettato con successo" << endl; 

    return; 
}

//metodo montecarlo

double int_ril (int k, double a, double b, double (*f)(double x) ){ // calcola integrale di f(x) in [a,b]

    double dx; 
    double F = 0; 
    double x;
    double A=0; 

    dx = (b-a)/k; 


    for ( int e = 0; e < k; e++){  //sommatoria delle f(x)
        x= randunif(a,b); 
        F= F + (*f)(x);
        
    }

    A= dx*F; 

    return A; 

}


bool is_inside (double y, double x ,double (* f)(double x)){ // controlla se (x,y) e' dentro l'area sottesa a f(x) 
    if(abs(y)<= abs((*f)(x))){
        return true; 
    }
    return false; 
}



double ril_area(int k, double a, double b, double (* f)(double x), double max, double min){ //ritorna l'area della funzione f in [a, b]
    ofstream file_out; 

    int c_i = 0;  
    double x,y;
    double A, E; 

    file_out.open("check1.txt", ios_base::app); 
    

    for ( int e = 0; e < k; e++){  //sommatoria delle f(x)
        x= randunif(a,b);
        y = randunif(min,max);
        //file_out << x << setw(10) << y; 
        bool status = is_inside(y,x,f); 
        //file_out << setw(12) << status << endl; 
        if(status){
            c_i++; 

        }
    }
    E= abs(a-b)*abs(min - max); 
    cout << E << endl;  
    file_out << c_i << endl; 
    A= ((double)c_i/k)*E; 
    return A; 

}