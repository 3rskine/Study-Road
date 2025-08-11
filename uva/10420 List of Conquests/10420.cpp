#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略換行符

    map<string, int> countryCount; // 自動依 key 排序

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string country;
        ss >> country; // 第一個單字就是國家
        countryCount[country]++;
    }

    // 輸出
    for (auto &p : countryCount) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
