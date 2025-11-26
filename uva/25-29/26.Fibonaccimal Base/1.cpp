#include <bits/stdc++.h>
using namespace std;

int main(){
    int f[40] = {0,1};
    for (int i = 2; i < 40; i++)f[i] = f[i-1] + f[i-2];
    int n; cin >> n;
    while(n--){
        int m; cin >> m ; cout << m << " = ";
        bool hadone = false;
        for (int i = 39; i >= 2 ; i--){
            if(m >= f[i]){
                cout << "1";
                m -= f[i];
                hadone = true;
            }else if(hadone)cout << "0";
        } 
        cout << " (fib)" << endl;
    } 
    return 0;
}