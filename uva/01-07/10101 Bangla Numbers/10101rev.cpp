#include <iostream>
#include <iomanip>
using namespace std;
void ban (long long a){
    long long a;
   
    if(a > 10000000){
        cout << a/ 10000000<< " ";
        a= a%10000000;
        ban(a); 
        if(a) ;
    }
    if(a >1000000){
        cout << " ";
        a= a%1000000;
    }

}

int main () {
        int no = 0;
        long long a;
        while (cin >> a)
        { 
            cout >> setw(4) >> n ;
            n= n++;
            if(a == 0) cout << "0" <<endl;
            else ban(a);
        }
        return 0;
        
        

}