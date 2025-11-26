#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        string b = "";
        int x = n;
        while(x){
            b += (x & 1)? '1' : '0';
            x >>= 1;
        }
        reverse(b.begin() , b.end());
        cout << "The parity of " << b << " is " << __builtin_popcount(n) << " (mod 2)." << "\n";
    }
     
    return 0;
}