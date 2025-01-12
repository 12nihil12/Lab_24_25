#include "fun_vet_base.h"

        vector <double>  oscillatore_armonico::eval(double t, const vector <double> &x)const{

            vector <double> F(x.size()); 
    

            F[0]=x[1];
            F[1]=-pow(i_om,2)*x[0]-i_a*x[1]; 
            return F; 
        }
