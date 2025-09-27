#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int M, N, Q;
        cin >> M >> N >> Q;
        vector<string> grid(M);
        for(int i = 0; i < M; i++) cin >> grid[i];

        cout << M << " " << N << " " << Q << "\n";

        for(int q = 0; q < Q; q++) {
            int r, c;
            cin >> r >> c;
            char centerChar = grid[r][c];
            int maxLen = 1; // 最小正方形邊長是1

            for(int k = 1; ; k++) { // k 是半徑
                bool ok = true;
                int x1 = r - k, y1 = c - k;
                int x2 = r + k, y2 = c + k;

                if(x1 < 0 || y1 < 0 || x2 >= M || y2 >= N) break; // 超出邊界

                for(int i = x1; i <= x2 && ok; i++)
                    for(int j = y1; j <= y2; j++)
                        if(grid[i][j] != centerChar)
                            ok = false;

                if(!ok) break;
                maxLen = 2*k + 1; // 邊長 = 半徑*2 + 1
            }

            cout << maxLen << "\n";
        }
    }
    return 0;
}
