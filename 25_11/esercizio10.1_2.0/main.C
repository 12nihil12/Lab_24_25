#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <sys/stat.h>


#include <exception> 

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TColor.h"
#include "TSystem.h"
#include "TH1F.h"

#include "gen_rand.h"

using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {



    if(argc!=3){
        cout << "Usage of "<< argv[0] << " <seed>  <number of elements to sum> " << endl; 
    }
    unsigned int seed=atoi(argv[1]);
    unsigned int N=atoi(argv[2]);

    gen_rand gen (seed); 


     TApplication app("app",0,0);


   int n_max=10000; 

  TCanvas c("Distribuzioni","Distribuzioni") ;

  c.Divide(3,4);
    

  vector <TH1F> somma(12) ; 

  for(int N=0; N<12; N++){
  
    string title = "N=" + to_string(N); 
    TH1F sum(title.c_str(),title.c_str(),100,0,N+1) ;
//    somma.push_back(sum);
    somma[N] = sum;
    for ( int k = 0 ; k < n_max ; k++ ) {
      double s=0; 
      for(int n=0; n<= N; n++){
        double v=gen.rand();
        s=s+v;
        //usleep(10000);
      }
      somma[N].Fill(s) ; 
    }

    c.cd(N+1);
    somma[N].GetXaxis()->SetTitle("x [AU]");
    somma[N].GetYaxis()->SetTitle("N");
    somma[N].Draw();

  }


 

  app.Run();
    return 0; 
}