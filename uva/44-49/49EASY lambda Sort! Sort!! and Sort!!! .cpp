#include <bits/stdc++.h>
using namespace std;

bool cpr (int a , int b ,int M){
    int mda = a % M;
    int mdb = b % M;

    if(mda != mdb) return mda < mdb;

    bool oda = a % 2 != 0;
    bool odb = b % 2 != 0;

    if(oda != odb) return oda;
    if(oda && odb) return a > b;
    if(!oda && !odb) return a < b;

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int N , M;
    while (cin >> N >> M)
    {
        cout << N << " " << M << "\n";
        if (N == 0 && M == 0) break;

        vector<int> numchain(N);
        for (int i = 0; i < N; i++) cin >> numchain[i];

        sort(numchain.begin() , numchain.end() ,[&](int a , int b){return cpr(a , b , M);});

        for (int x : numchain) cout << x << "\n";
        
    }
    
    return 0;
}