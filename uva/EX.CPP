#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        if (m == 1 && n != 1) { cout << "Boring!\n"; continue; }
        vector<long long> a;
        for (long long x = n; ; x /= m) {
            a.push_back(x);
            if (x == 1) break;
            if (x % m) { cout << "Boring!\n"; goto end; }
        }
        for (auto v : a) cout << v << " "; 
        cout << "\n";
        end:;
    }
}
