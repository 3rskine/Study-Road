#include <iostream>
#include <iomanip>
using namespace std;
void ban (long long a){
   
    if(a >= 10000000){
        ban(a /10000000); 
        cout << " kuti";
        a %= 10000000;
        if(a) cout<< " ";
    }
    if(a >=100000){
        cout << a/100000 << " lakh";
        a%=100000;
        if(a) cout<< " ";
    }
    if(a >=1000){
        cout << a/1000 << " hajar";
        a%=1000;
        if(a) cout<< " ";
    }
    if(a >=100){
        cout << a/100 << " shata";
        a%=100;
        if(a) cout<< " ";
    }
    if (a>0){
        cout << a ;
    }

}

int main () {
        int no = 1;
        long long a;
        while (cin >> a)
        { 
            cout << setw(4) << no << "." ;
            no +=1;
            if(a == 0) cout << " 0" <<endl;
            else {
                cout << " ";
                ban(a);
                cout<<endl;
            }
        }
        return 0;
        
        

}