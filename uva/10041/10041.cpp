#include <iostream>      // 輸入輸出
#include <vector>        // 動態陣列
#include <algorithm>     // sort() 排序函數
#include <cmath>         // abs() 絕對值函數
using namespace std;


int main() {
    int t; // 測資數
    cin >> t; // 例如輸入 2 表示有兩組測資

    while (t--) { // 執行 t 次
        int r; // r 是親戚人數
        cin >> r;

        vector<int> streets(r); // 宣告一個長度 r 的陣列，裝每位親戚的街號

        // 輸入每位親戚的街號
        for (int i = 0; i < r; ++i) {
            cin >> streets[i];
        }

        // 排序街號：例如 6 2 4 → 排成 2 4 6
        sort(streets.begin(), streets.end());

        // 中位數（r / 2）：如果 r=3 → index = 1 → 第 2 個數
        int median = streets[r / 2];

        // 計算每個親戚到 median 的距離總和
        int total_distance = 0;
        for (int i = 0; i < r; ++i) {
            total_distance += abs(streets[i] - median);
        }

        // 輸出總距離
        cout << total_distance << endl;
    }

    return 0;
}
