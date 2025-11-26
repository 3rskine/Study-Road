#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        int b1 = 0, b2= 0;
        for (int i = m ; i ; i /= 2)b1 += i%2;
        for (; m ; m/= 10)for (int i = m % 10; i ; i /= 2) b2 += i%2;   
        cout << b1 << " " << b2 << endl;
    }
    
    return 0;
}   