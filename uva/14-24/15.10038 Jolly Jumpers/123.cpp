#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {//每當輸入n，隨後會有n筆資料進行比對
        vector<int> a(n); //設一個大小為n的vec容器
        for (int i = 0; i < n; i++) cin >> a[i];//將n筆資料傳入該陣列

        vector<bool> seen(n, false);//另設一容器紀錄flags
        for (int i = 1; i < n; i++) { //假設一張從1~n-1的集點卡，如果所有*洞*都被填補(狀態=1)，則該數符合Jolly number
            int d = abs(a[i] - a[i-1]);//紀錄前後兩數字差值為d
            if (d < n) seen[d] = true; //因為jolly num一定是從1到小於n-1的自然數列，所以當差值>=n時根本不用紀錄(戳洞)
        }

        bool ok = true;
        for (int i = 1; i < n; i++)//從1到n-1(兩數字差值指會有n-1個)
            if (!seen[i]) ok = false;//只要有任何一個seen的狀態為false，則jolly條件不成立

        cout << (ok ? "Jolly\n" : "Not jolly\n");
    }
}
