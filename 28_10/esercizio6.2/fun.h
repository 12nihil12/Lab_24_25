#ifndef fun_h
#define fun_h


class fun{
    public:
        virtual double eval(double x) =0; 
        int sign(double x){
           if(eval(x)==0){return 0;} 
           else if (eval(x)>0){return 1;} 
           else{return -1;};
        }

};


class parabola:public fun{
    public:
        parabola(double a,double b,double c){pa=a;pb=b;pc=c;}


        double geta(){return pa;}
        double getb(){return pb;}
        double getc(){return pc;}
        virtual double eval(double x){return pa*x*x+pb*x+pc;}


    private:
        double pa;
        double pb; 
        double pc;


};




#endif