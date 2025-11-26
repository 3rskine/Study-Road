#include <bits/stdc++.h>
using namespace std;

int main(){
    int t , n ,casenum = 0; cin >> t;
    while(t--){
        string ign;
        cin >> ign >> ign >> n;
        long long arr[n][n];
        for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> arr[i][j];
        bool issym = 1;
        for (int i = 0; i < n && issym; i++)for (int j = 0; j < n && issym; j++){
            if(arr[i][j] != arr[n-1-i][n-1-j] || arr[i][j] < 0) issym = 0;
        }
        cout << "Test #" << ++casenum <<": " << ((issym == 1) ? "Symmetric.\n" : "Non-symmetric\n");
    }     
    return 0;
}