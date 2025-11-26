#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll s , d;
    while(cin >> s >> d){
        ll size = s, start = 1, end = s;
        while(d > end){
            size++;
            end += size;
        }
        cout << size << endl;
    }
    return 0;
}