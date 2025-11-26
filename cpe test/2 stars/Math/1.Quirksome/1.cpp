#include <bits/stdc++.h>
using namespace std;

int main(){
    int d;
    while(cin >> d){
        int h = d/2, lim = pow(10,h);
        for (int i = 0;; i++){
            int x = i*i;
            if(x >= lim*lim) break;
            int a = x/lim, b = x%lim;
            if(a + b == i) cout << setw(d) << setfill('0') << x << "\n"; 
        } 
    }
    return 0;
}