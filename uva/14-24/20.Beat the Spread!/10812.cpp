#include <bits/stdc++.h>
using namespace std;
int main (){
    int n ;
    cin >> n;
    while (n--){
        long long s,d;
        cin >> s >>d;
        long long a = (s+d) / 2 ;
        long long b = a - d;
        if ( d > s || (s+d) % 2 == 1 ) cout << "impossible" << endl;       
        else cout << a << " " << b << endl;
    }
    return 0;
}