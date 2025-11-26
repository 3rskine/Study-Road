#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
  int base[13] = {0, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
  vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    while(t--){
        int m , d;cin >> m >> d;
        int offset = d - base[m];
        int modday = (offset + 35) %7;
        cout << week[modday] << endl;
    }
    return 0;
}