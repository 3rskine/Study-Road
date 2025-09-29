#include <bits/stdc++.h>
using namespace std;

// 把一個十進位數字轉換成 base 進位表示，並計算字元成本
int calculateCost(long long number, int base, const vector<int>& costTable) {
    if (number == 0) return costTable[0]; // 特例：0 的成本就是 '0'
    int totalCost = 0;
    while (number > 0) {
        int digit = number % base;   // 取出餘數 (進位數字)
        totalCost += costTable[digit]; // 加上對應字元的成本
        number /= base;              // 繼續處理下一位
    }
    return totalCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 測資數量
    cin >> T;

    for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
        // 讀取 36 個字元的成本表
        vector<int> costTable(36);
        for (int i = 0; i < 36; i++) {
            cin >> costTable[i];
        }

        cout << "Case " << caseNumber << ":\n";

        int Q; // 查詢數量
        cin >> Q;
        while (Q--) {
            long long number;
            cin >> number;

            // 儲存每個 base 的成本
            vector<int> baseCost(37, 0);
            int minCost = INT_MAX;

            // 計算每一個 base (2 ~ 36) 的成本
            for (int base = 2; base <= 36; base++) {
                baseCost[base] = calculateCost(number, base, costTable);
                minCost = min(minCost, baseCost[base]); // 更新最小成本
            }

            // 輸出結果
            cout << "Cheapest base(s) for number " << number << ":";
            for (int base = 2; base <= 36; base++) {
                if (baseCost[base] == minCost) {
                    cout << " " << base;
                }
            }
            cout << "\n";
        }

        if (caseNumber < T) cout << "\n"; // case 之間空一行
    }

    return 0;
}
