#ifndef particella_h
#define particella_h

#include <iostream> 
using namespace std; 
class particella{



    public:
        particella(double mp,double qp);


        double getm() const {return m;};
        double getq() const {return q;};
        
        virtual void print_p(){cout << "Particella || m : " << getm() << " kg | q : " << getq() << " C" << endl;};

    protected:
        double m;
        double q;
};

class elettrone : public particella{

    public:
        elettrone():particella(9.1093837e-31,1.60217663e-19) {};  
    
        virtual void print_p(){ cout << "Elettrone || m : " << getm() << " kg | q : " << getq() << " C" << endl; };

};

#endif