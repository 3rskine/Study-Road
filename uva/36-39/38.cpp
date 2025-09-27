#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    for (int caseNumber = 1; caseNumber <= testCases; caseNumber++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 差值
        long long deltaX = x2 - x1;
        long long deltaY = y2 - y1;

        // 基本步數：就是座標和的差
        long long steps = (x2 + y2) - (x1 + y1);

        // 如果不在「對角線」上，還要再多加 1
        if (deltaX != deltaY) steps++;

        cout << "Case " << caseNumber << ": " << steps << "\n";
    }

    return 0;
}
