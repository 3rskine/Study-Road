#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int total = N;
        int empty = N;

        while (empty >= 3) {
            int newBottles = empty / 3;
            total += newBottles;
            empty = empty % 3 + newBottles;
        }

        // 借瓶策略：最後剩 2 個空瓶時
        if (empty == 2) total++;  // 借 1 瓶換 1 瓶可樂

        cout << total << endl;
    }
    return 0;
}
