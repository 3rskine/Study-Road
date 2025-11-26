#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll x;
    while(cin >> x){
        cin.ignore();
        string coefline;
        getline(cin , coefline);
        stringstream ss(coefline);
        vector<ll> coeftable;
        ll num;
        while(ss >> num) coeftable.push_back(num);

        int highestdeg = coeftable.size() - 1;
        ll res = 0;
        for (int i = 0; i < coeftable.size() - 1; i++){
            ll npow = highestdeg - i;
            res = x * res + coeftable[i] * npow;
        } 
        cout << res << endl;

    }
    return 0;
}