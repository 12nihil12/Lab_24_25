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



    if(argc!=2){
        cout << "Usage of "<< argv[0] << " <seed>" << endl; 
    }
    unsigned int seed=atoi(argv[1]);

    gen_rand gen (seed); 
    cout << seed << endl; 

     TApplication app("app",0,0);

  int nmax = 10000;

  TH1F unif("Uniforme","Uniforme",70,4,11) ;
  TH1F esp("Esponenziale","Esponenziale",70,0,10) ;
  TH1F gauss("Gauss","Gauss",70,-5,7) ;
  TH1F gaussAR("Gauss AR","Gauss AR ",70,-5,7) ;

  for ( int k = 0 ; k < nmax ; k++ ) {
    //cout << v << endl;
    unif.Fill(gen.unif(5,10)) ;  
    esp.Fill(gen.esp(1));
    // aggiungere le altre distribuzioni
    gauss.Fill(gen.gauss(1,1));
    gaussAR.Fill(gen.AR(1,1));

  }

  TCanvas c("Distribuzioni","Distribuzioni") ;
  c.Divide(2,2);
  c.cd(1);
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();
  c.cd(2);

    esp.GetXaxis()->SetTitle("x [AU]");
  esp.GetYaxis()->SetTitle("N");
  esp.Draw();


 c.cd(3);

  gauss.GetXaxis()->SetTitle("x [AU]");
  gauss.GetYaxis()->SetTitle("N");
  gauss.Draw();


 c.cd(4);

  gaussAR.GetXaxis()->SetTitle("x [AU]");
  gaussAR.GetYaxis()->SetTitle("N");
  gaussAR.Draw();

  app.Run();



    return 0; 
}