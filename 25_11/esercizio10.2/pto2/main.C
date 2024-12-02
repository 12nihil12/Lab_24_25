#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <sys/stat.h>
#include <fstream>
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


  cout << "Checking existence of <int_values/> directory" << endl; 
  if( mkdir("int_values",0777) !=0){
  if(errno==EEXIST){
    cout << "Directory already exists." << endl; 
  } else{
    cout << "Unexpected error. Try manually creating a folder named <int_values>" << endl; 
    return 0; 
  }
  }else{
  cout << "Directory <int_values/> created" << endl; 
  }

  TApplication app("app",0,0);
   
   auto * f= new myfun(); 


  auto * integral = new media(0,M_PI/2,1); 

  gen_rand gen(1);


  double s=0; 


  //vector <TH1F*> hist_vec(6); 
  //TCanvas c; 
  //c.Divide(3,2); 

  ofstream fileout; 

  int N=500; 
  for(int k=0; k < 4; k++){

    if(k!=0){
      N=(k%2!=0)?N*2: N*5; 
    }
    

    string name = "int_values/N_" +to_string(N) + ".txt"; 
    cout << name << endl; 
    fileout.open(name.c_str()); 

    cout << "N=" << N << endl; 
    //hist_vec[k]=new TH1F("Histogram","Histogram",100,0.80,1.20 );
   
    
    for(int i=0; i<=10000; i++){

      double iv= integral->calc(f, N) ; 
      fileout << iv << endl; 
      //s=s + iv;

      //hist_vec[k]->Fill(iv); 

    }
    //c.cd(k+1);
    //hist_vec[k]->Draw("AL*"); 
    fileout.close();

  }
  

  

  return 0; 
}