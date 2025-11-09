
#include <bits/stdc++.h>
using namespace std;

int calbasecost(long long num , int base , const vector <int> &costtable){
    if(num == 0) return costtable[0];
    int totalcost = 0;
    while(num > 0){
        int digit = num % base;
        totalcost += costtable[digit];
        num /= base;
    }
    return totalcost;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;cin >> T;
    for(int casenum = 1 ; casenum <= T ; casenum++){
        vector<int> costtable(36);
        for (size_t i = 0; i < 36; i++)
        {
            cin >> costtable[i];
        }
        cout << "Case "<< casenum <<":\n";

        int q; cin >> q;
        while(q--){
            long long num;
            cin >> num;

            vector<int> basecost(37 , 0);
            int mincost = INT_MAX;

            for (int base = 2; base < 37; base++)
            {
                basecost[base] = calbasecost(num , base , costtable);
                mincost = min(mincost , basecost[base]);
            }
            cout << "Cheapest base(s) for number " << num << ":";
            for (int base = 2; base < 37; base++)
            {
                if(basecost[base] == mincost){
                    cout << " " << base;
                }
            }
            cout << "\n";
        }
        if (casenum < T) cout << "\n";
    }
    return 0;
}