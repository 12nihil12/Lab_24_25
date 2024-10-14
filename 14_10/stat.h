#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath> 
#include <vector> 
#include <algorithm> 
#include <string>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"

#include "in_out.h"
#include "stat.h" 


using namespace std; 



template <typename T> double mediana (vector<T> v);
double mediana (vector<int> v); 

template <typename T>  T media (const vector<T>& v);
double media (const vector<int> & v);

template <typename T> double varianza (const vector<T> & v, double x); // varianza (avendo gia` la media)

double calc_mean_delta(int i); 



template <typename T> T mediana (vector<T> v){
    sort(v.begin(), v.end()); 
    if(v.size()%2==0){
        return (v[v.size()/2 -1 ]+v[v.size()/2 ])/2;
    } else {
        return v[(v.size()+1)/2 -1]; 
    }
}

double mediana (vector<int> v){
    sort(v.begin(), v.end()); 
    if(v.size()%2==0){
        return (double)(v[v.size()/2 -1 ]+v[v.size()/2 ])/2;
    } else {
        return (double)v[(v.size()+1)/2 -1]; 
    }
}

template <typename T> T media (const vector<T> & v){

    T conta = 0; 
    for( int c= 0; c < v.size(); c++){
        conta= conta*c/(c+1) + v[c]/(c+1);
    }

    return conta; 
}


 double media (const vector<int> & v){

    double conta = 0; 
    for( int c= 0; c < v.size(); c++){
        conta= conta*c/(c+1) + (double)v[c]/(c+1);
    }

    return conta; 
}




template <typename T> double varianza (const vector<T> & v , double x) { // varianza (avendo gia` la media)

    double scarto = 0;

    int count=0; 
     for( int c= 0; c < v.size(); c=c+6){
        scarto = scarto + pow((x - (double)v[c]), 2); 
        count++; 
    }

    return scarto/count; 
}

void to_char(string str, char * arr){
    int n = str.length();
  
     arr= new char [n+1];

    cout << "HI"; 
  
    // Specify the ranges
    auto first = str.begin();
    auto last = str.end();
  
    // Convert the string to char array
    copy(first, last, arr);
    
    // Null terminate the char array
    arr[n] = '\0';

    return; 
    
}


double calc_mean_delta(int i){
    string nomefile= "Data/" + to_string(i) + ".txt"; 
    cout << nomefile << endl;
    char * nfchar; 
    to_char(nomefile, nfc);
    cout << nfchar[i]; 
    
    vector <double> v= loadff<double>(nfchar); 

    string histoname= "Delta temperature " + nomefile +"-today"; 
    char * hischar; 
    to_char(histoname); 
    TH1F histo ("histo",hischar, 100, -10, 10) ;
    histo.StatOverflows( kTRUE );
    for ( int k = 0 ; k < v.size() ; k++ ) histo.Fill( v[k] );
    
    TCanvas mycanvas ("Histo","Histo");
    histo.GetXaxis()->SetTitle("Delta");
    string nm = "graph/" + to_string(i) + ".pdf"; 
    char * nmc; 
    to_char(nm); 
    mycanvas.Print(nmc);
    
    
    return histo.GetMean(); 
}

#endif