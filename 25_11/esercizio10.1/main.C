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
  TH1F unif("Uniforme","Uniforme",70,4,11) ;

  TH1F somma("Uniforme","Uniforme",70,N*4,N*11) ;

  for ( int k = 0 ; k < n_max ; k++ ) {
    double s=0; 

    for(int n=0; n< N; n++){
      double v=gen.unif(5,10);
      unif.Fill(v);
      s=s+v;
      //usleep(10000);
    }
    somma.Fill(s) ;  
    

  }

  TCanvas c("Distribuzioni","Distribuzioni") ;
  c.Divide(1,2);
  c.cd(1);
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();
  c.cd(2);
    somma.GetXaxis()->SetTitle("x [AU]");
  somma.GetYaxis()->SetTitle("N");
  somma.Draw();
 

  app.Run();
    return 0; 
}