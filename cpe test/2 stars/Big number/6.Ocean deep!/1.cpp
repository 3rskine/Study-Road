#include <bits/stdc++.h>
using namespace std;

int main(){
    const int mod =131071;
    string s;
    int value = 0;
    while(cin >> s){
        for (char c : s){
             if (c == '#') {
                cout << (value == 0 ? "YES\n" : "NO\n");
                value = 0;
            } else {
                value = (value * 2 + (c - '0')) % mod;
            }
        } 
    }
    return 0;
}