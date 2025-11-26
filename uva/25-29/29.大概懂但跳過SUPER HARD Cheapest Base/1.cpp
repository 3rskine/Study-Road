#include <bits/stdc++.h>
using namespace std;

int calcost(long long number, int base, const vector<int>& costtable) {
    if (number == 0) return costtable[0];
    int totalcost = 0;
    while (number > 0) {
        int digit = number % base;
        totalcost += costtable[digit];
        number /= base;
    }
    return totalcost;
}

int main() {
    int T; 
    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++) {
        vector<int> costtable(36);  // 正確宣告
        for (int i = 0; i < 36; i++) cin >> costtable[i];

        cout << "Case " << casenum << ":\n";

        int Q; 
        cin >> Q;
        while (Q--) {
            long long number; 
            cin >> number;

            vector<int> basecost(37, 0);
            int mincost = INT_MAX;

            for (int base = 2; base <= 36; base++) {
                basecost[base] = calcost(number, base, costtable);
                mincost = min(mincost, basecost[base]);
            }

            cout << "Cheapest base(s) for number " << number << ":";
            for (int base = 2; base <= 36; base++) {
                if (basecost[base] == mincost) {
                    cout << " " << base;
                }
            }
            cout << "\n";
        }

        if (casenum < T) cout << "\n";
    }
    return 0;
}
