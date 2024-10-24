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
template <typename T> double varianza (const vector<T> &v); // varianza 




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
     for( int c= 0; c < v.size(); c++){
        scarto = scarto + pow((x - (double)v[c]), 2); 
        count++; 
    }

    return scarto/count; 
}


template <typename T> double varianza (const vector<T> & v) { // varianza (avendo gia` la media)

    double x= media <double> (v);
    double scarto = 0;

     for( int c= 0; c < v.size(); c++){
        scarto = scarto + pow((x - (double)v[c]), 2); 
    }

    return scarto/v.size(); 
}


void calc_stat(const vector<double> &v, double & med,double & err){

    vector <double> v_calc_err; 
    
    //err.push_back(varianza <double> (v));
     for(int c=0; c < v.size(); c++){
            if(c%7==0){
                v_calc_err.push_back(v[c]);
            }
        }
    med= media <double> (v_calc_err);
    err= sqrt((varianza <double> (v_calc_err,med))/(v_calc_err.size()));
    return; 

}
void histo_op_delta(int i, vector <double> &  v){

    
    //string nomefile= "Data/" + to_string(i) + ".txt"; 

    //vector <double> v= loadff<double>(nomefile.c_str()); 

    //string nm = "copy/" + to_string(i) + ".txt"; 
    
    //print(nm.c_str(), v);
    string histoname= "Delta temperature " + to_string(i); 

    TH1F histo ("histo",histoname.c_str(), 100, -10, 10) ;
    histo.StatOverflows( kTRUE );
    for ( int k = 0 ; k < v.size() ; k++ ) histo.Fill( v[k] );
    
    TCanvas mycanvas ("Histo","Histo");
    histo.Draw();
    histo.GetXaxis()->SetTitle("Delta temperature (#circ C )");
    histo.GetYaxis()->SetTitle("Frequency");

    string graph_print = "graph/" + to_string(i) + ".pdf"; 
 
    mycanvas.Print(graph_print.c_str());
    
    return; 
}

#endif