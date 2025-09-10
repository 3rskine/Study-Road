#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 快速 I/O
    cin.tie(nullptr);

    long long S, D;
    while (cin >> S >> D) {
        long long low = 0, high = 2000000000LL; // k 的可能範圍
        while (low < high) {
            long long mid = low + (high - low) / 2;
            // 計算總天數 (用 __int128 避免溢位)
            __int128 sum = (__int128)(mid+1) * S + (__int128)mid * (mid+1) / 2;
            if (sum >= D) high = mid;
            else low = mid + 1;
        }
        cout << (S + low) << "\n";
    }
    return 0;
}
