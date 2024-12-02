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
#include "fun.h"
#include "integrator.h"
using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {


      TApplication app("app",0,0);
   
   auto * f= new myfun(); 


  auto * integral = new media(0,M_PI/2,2); 

  double s=0; 

  TH1F histo("Histogram","Histogram",100,0.70,1.30 );

  for(int i=0; i<=10000; i++){

    double iv= integral->calc(f, 100) ; 
   s=s + iv;

   histo.Fill(iv); 

  }

  TCanvas c; 
  histo.Draw(); 
  cout << s/10000 << endl;

  app.Run(); 

  return 0; 
}