#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
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
      cout << "Uso di"<< argv[0] << " <seed>" << endl; 
      return 0;
  }
  unsigned int seed=atoi(argv[1]);

  gen_rand gen (seed); 
  

  TApplication app("app",0,0);

  int nmax = 100000;

  cout << "Parametri:  seed = " << seed << " | n_max = " << nmax << endl; 


  TH1F unif("Uniforme","Uniforme",70,4,11) ;
  TH1F esp("Esponenziale","Esponenziale",70,0,10) ;
  TH1F gauss("Gauss","Gauss",70,-5,7) ;
  TH1F gaussAR("Gauss AR","Gauss AR ",70,-5,7) ;

  for ( int k = 0 ; k < nmax ; k++ ) {
    unif.Fill(gen.unif(5,10)) ;  
    esp.Fill(gen.esp(1));
    gauss.Fill(gen.gauss(1,1));
    gaussAR.Fill(gen.AR(1,1));

  }

  TCanvas c("Distribuzioni","Distribuzioni") ;
  c.Divide(2,2);

  c.cd(1);
  gPad->SetGrid();
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();

  c.cd(2);
  
  gPad->SetGrid();
  esp.GetXaxis()->SetTitle("x [AU]");
  esp.GetYaxis()->SetTitle("N");
  esp.Draw();


  c.cd(3);
  gPad->SetGrid();
  gauss.GetXaxis()->SetTitle("x [AU]");
  gauss.GetYaxis()->SetTitle("N");
  gauss.Draw();


  c.cd(4);
  gPad->SetGrid();
  gaussAR.GetXaxis()->SetTitle("x [AU]");
  gaussAR.GetYaxis()->SetTitle("N");
  gaussAR.Draw();

  app.Run();



  return 0; 
}