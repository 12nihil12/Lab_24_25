#ifndef particella_h
#define particella_h

class particella{



    public:
        particella(double mp,double qp);


        double getm() const {return m;};
        double getq() const {return q;};
        
        void print_p();

    protected:
        double m;
        double q;
};

class elettrone : public particella{

    public:
        elettrone():particella(9.1093837e-31,1.60217663e-19) {};  
        void print_p();

};

#endif