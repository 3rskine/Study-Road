#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll x;
    while(cin >> x){
        cin.ignore();
        string coeflist;
        getline(cin , coeflist);
        stringstream ss(coeflist);
        ll coefnum;
        vector<ll> list;
        while(ss >> coefnum)list.push_back(coefnum);
        ll highestdegree = list.size() - 1;
        ll tmp = 0;
        for (int i = 0; i < list.size() - 1; i++){
            ll npow = highestdegree - i;
            tmp = x * tmp + npow * list[i];
        } 
        cout << tmp << endl;
    }
    return 0;
}