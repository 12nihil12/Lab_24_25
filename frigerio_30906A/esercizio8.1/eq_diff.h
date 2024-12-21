#ifndef eq_diff_h
#define eq_diff_h



class eq_diff{
    public:
     eq_diff(vector <double> x_0, double t_0) { i_t_0= t_0; i_x_0= x_0;}; 
        virtual vector <double>  step(const vector <double> &x, double t, double h, fun_vet_base * f) const =0; 
       vector <double>   get_x_0(){return i_x_0;}; 
       double  get_t_0(){return i_t_0;}; 

    protected:
        vector <double> i_x_0; 
        double i_t_0; 
};


class eulero:public eq_diff {
    public:
    eulero(vector <double> x_0, double t_0) : eq_diff(x_0,t_0){;};
        virtual vector <double>  step(const vector <double> &x, double t, double h, fun_vet_base * f) const override{
            return x + h*f->eval(t,x); 
        }; 

}; 

#endif