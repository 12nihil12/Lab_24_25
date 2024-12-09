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
#include "TF1.h"


#include "gen_rand.h"
#include "prisma.h"
using namespace std;


vector <int> convert(double s); 


int main(int argc, char** argv) {

    TApplication app("app",0,0);
    prisma esp(1); 

    vector <TH1F *> hist(3);

    TCanvas c("Distr","Distr");
    c.Divide(1,3);

    hist[0]= new TH1F("#theta_{0}","#theta_{0}",100,1,0);
    hist[1]= new TH1F("#theta_{1}","#theta_{1}",100,1,0) ;
    hist[2]= new TH1F("#theta_{2}","#theta_{2}",100,1,0) ;
    hist[0]->StatOverflows( kTRUE );
    hist[1]->StatOverflows( kTRUE );
    hist[2]->StatOverflows( kTRUE );


    for(int i=0; i<10000; i++){
        esp.misura();
        hist[0]->Fill(esp.get_th0());
        hist[1]->Fill(esp.get_th1());
        hist[2]->Fill(esp.get_th2());

    
    }
    

    c.cd(1);
    gPad->SetGrid();

    hist[0]->Draw();
   


    c.cd(2);
    gPad->SetGrid();

    hist[1]->Draw();

    c.cd(3);
    gPad->SetGrid();

    hist[2]->Draw();
   



    cout << "Theta_0 |   MEDIA:" << fixed<<  setprecision(4) << hist[0]->GetMean() << "    |   DEV.STD:"  << hist[0]->GetStdDev() << endl;
    cout << "Theta_1 |   MEDIA:"  << hist[1]->GetMean() << "    |   DEV.STD:"  <<hist[1]->GetStdDev() << endl;
    cout << "Theta_2 |   MEDIA:"  << hist[2]->GetMean() << "    |   DEV.STD:"  << hist[2]->GetStdDev() << endl;

    app.Run();

  return 0; 
}