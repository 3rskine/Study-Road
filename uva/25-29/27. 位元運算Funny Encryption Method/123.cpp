#include <bits/stdc++.h>
using namespace std;

int counthowmany1 (long long x){
    int count = 0;
    while (x) // if x =000000... break the while loop
    {
        if(x & 1){
        count++;
        }
        x >>= 1;
    } 
    return count;
}

//counthowmany1(x) == __builtin_popcount(x)

int main (){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    while (n--){
        string M;
        cin >> M;

        long long decBase = stoll(M , nullptr , 10);
        long long b1 = counthowmany1 (decBase);

        long long HexBase = stoll(M , nullptr , 16);
        long long b2 = __builtin_popcount(HexBase);

        cout << b1 << " " << b2 << "\n";
    }
    return 0;
}