#include <bits/stdc++.h>
using namespace std;

int main(){
    int V , V0;
    while(cin >> V >> V0 , V || V0){
        int m =(int)(V / V0);
        if( m < 1){cout << 0 << "\n"; continue;}
        
        double bestn = V / (2.0*V0);
        int a = floor(bestn) , b = ceil(bestn);
        vector<int> cand;

        if (a >= 1 && a < m) cand.push_back(a);
        if (b >= 1 && b < m && b != a) cand.push_back(b); // 避免重複

        
        int bst = -1;
        int ans = 0 , cnt = 0;
        for(int n : cand){
            int L = n * (V - n*V0); 
            if(L > bst) {bst = L; ans = n; cnt = 1;}
            else if(L == bst)cnt++;
        }
        if(cnt > 1) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}