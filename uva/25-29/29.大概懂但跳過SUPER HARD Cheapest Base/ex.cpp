#include <bits/stdc++.h>
using namespace std;

// 把一個十進位數字轉換成 base 進位表示，並計算字元成本
int calculateCost(long long number, int base, const vector<int>& costTable) {
    if(number == 0)return costTable[0];
    int totalcost = 0;
    while(number > 0){
        int digit =  number % base;
        totalcost += costTable[digit];
        number /= base;
    }
    return totalcost; 
}

int main() {
    int T;  cin >> T;
    for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
        vector<int> costTable(36);
        for (int i = 0; i < 36; i++) cin >> costTable[i];
        cout << "Case " << caseNumber << ":\n";
        int Q; cin >> Q;
        while (Q--) {
            long long number; cin >> number;
            vector<int> baseCost(37, 0);
            int minCost = INT_MAX;

            for (int base = 2; base <= 36; base++) {
                baseCost[base] = calculateCost(number, base, costTable);
                minCost = min(minCost, baseCost[base]); // 更新最小成本
            }

            cout << "Cheapest base(s) for number " << number << ":";
            for (int base = 2; base <= 36; base++) {
                if (baseCost[base] == minCost) {
                    cout << " " << base;
                }
            }
            cout << "\n";
        }
        if (caseNumber < T) cout << "\n"; 
    }
    return 0;
}
