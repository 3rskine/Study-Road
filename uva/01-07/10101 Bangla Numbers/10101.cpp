#include <iostream>
#include <iomanip>
using namespace std;
void ban (long long n){
    if (n >= 10000000){
        ban(n/10000000 );
        cout<< " kuti";
        n %= 10000000;
        if (n) cout <<" ";        
        }
    if(n >= 100000){
        cout << n / 100000 << " lakh" ;
        n%= 100000;
        if (n) cout<< " ";
        }
    if(n >= 1000){
        cout << n / 1000 << " hajar" ;
        n%= 1000;
        if (n) cout<< " ";
        }
    if(n >= 100){
        cout << n / 100 << " shata" ;
        n%= 100;
        if (n) cout<< " ";
        }            
    if(n > 0){
        cout << n ;
        }
    }


int main(){
    long long n;
    int No = 1;
    while (cin >> n){
        cout << setw(4) << No++ << ".";

        if (n == 0)
        {
            cout << " 0" ;
        }
        else{
            cout << " ";
            ban(n);
        }
        cout<<endl;
        
    }
    return 0;
}