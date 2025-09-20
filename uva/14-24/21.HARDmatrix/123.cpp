#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        string tmp;
        cin >> tmp >> tmp >> n; // 讀 "N = 3"
        vector<vector<long long>> M(n, vector<long long>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> M[i][j];

        bool symmetric = true;
        for (int i = 0; i < n && symmetric; i++) {
            for (int j = 0; j < n && symmetric; j++) {
                if (M[i][j] < 0 || M[i][j] != M[n-1-i][n-1-j]) {
                    symmetric = false;
                }
            }
        }

        cout << "Test #" << t << ": ";
        cout << (symmetric ? "Symmetric." : "Non-symmetric.") << "\n";
    }

    return 0;
}
