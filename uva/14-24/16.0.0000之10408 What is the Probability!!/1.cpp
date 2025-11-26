#include <bits/stdc++.h>
using namespace std;

int main(){
    int s; cin >> s;
    cout << fixed << setprecision(4);
    while(s--){
        int n , i; double p;
        cin >> n >> p >> i;
        if(p == 0){cout << "0.0000\n"; continue;}
        double q = 1 - p;
        cout << (p * pow(q , i-1)) /(1 - pow(q , n)) << endl;
    }
    return 0;
}