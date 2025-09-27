#include <bits/stdc++.h>
using namespace std;

// 計算二進位 1 的個數
int countOnes(long long x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        string M_str;
        cin >> M_str;

        // b1: 把 M 當作十進位
        long long decimalValue = stoll(M_str, nullptr, 10);
        int b1 = countOnes(decimalValue);

        // b2: 把 M 當作十六進位
        long long hexValue = stoll(M_str, nullptr, 16);
        int b2 = countOnes(hexValue);

        cout << b1 << " " << b2 << "\n";
    }
    return 0;
}
