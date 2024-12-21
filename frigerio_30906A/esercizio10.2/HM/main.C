#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <iomanip> 
#include <cstring> 
#include <filesystem>
#include <fstream>

#include "gen_rand.h"
#include "fun.h"
#include "integrator.h"
using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {


  cout<< "Sto controllando l'esistenza della cartella <int_values/>" << endl; 

  if(!filesystem::create_directory("int_values")){
      cout << "La cartella esiste già" << endl; 
  }else{
      cout << "Cartella <int_values/> creata" << endl; 

  }
   
  auto * f= new myfun(); 


  auto * integral = new hitormiss(0,M_PI/2,1); 

  gen_rand gen(1);


  double s=0; 


  ofstream fileout; 

  int N=500; 
  for(int k=0; k < 6; k++){

    if(k!=0){
      N=(k%2!=0)?N*2: N*5; 
    }
    

    string name = "int_values/N_" +to_string(N) + ".txt"; 

    fileout.open(name.c_str()); 

    cout << "N=" << N << endl; 
  
    
    for(int i=0; i<10000; i++){

      double iv= integral->calc(f, N,M_PI/2) ; 
      fileout << iv << endl; 


    }
   
    fileout.close();

  }
  

  

  return 0; 
}