#include <iostream>
#include <iomanip>
using namespace std;

void bangla(long long n, bool st) {
    if (n >= 10000000) { // kuti
        bangla(n / 10000000, true);
        cout << " kuti";
        n %= 10000000;
        if (n) cout << " ";
    }
    if (n >= 100000) { // lakh
        cout << n / 100000 << " lakh";
        n %= 100000;
        if (n) cout << " ";
    }
    if (n >= 1000) { // hajar
        cout << n / 1000 << " hajar";
        n %= 1000;
        if (n) cout << " ";
    }
    if (n >= 100) { // shata
        cout << n / 100 << " shata";
        n %= 100;
        if (n) cout << " ";
    }
    if (n > 0) { // 剩下 < 100 的數字
        cout << n;
    }
}

int main() {
    long long n;
    int caseNo = 1;
    while (cin >> n) {
        cout << setw(4) << caseNo++ << ".";
        if (n == 0) {
            cout << " 0";
        } else {
            cout << " ";
            bangla(n, true);
        }
        cout << "\n";
    }
    return 0;
}
