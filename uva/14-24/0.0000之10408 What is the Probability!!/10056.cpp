#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main (){
    int k;
    cin >> k ;
    while (k--){
        int peoplAmouns , whoWin;
        double winsrate;
        cin >> peoplAmouns >> winsrate >> whoWin;
        double loserate = 1 - winsrate;
        double nu = (winsrate * pow( loserate ,whoWin - 1));
        double de = (1 - pow(loserate , peoplAmouns));
        double obprobty = nu / de;
        if(winsrate ==0) 
        {cout << "0.0000" << endl;}
        else{
        cout<< fixed << setprecision(4) << obprobty <<endl;}
    }
    return 0 ;

}