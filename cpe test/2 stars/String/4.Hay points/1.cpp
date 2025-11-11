#include <bits/stdc++.h>
using namespace std;
int main(){
    int m , n;
    cin >> m >> n; // m for table, n for essay 
    map<string , int> hay;
    string element;
    while (m--){
        int price;
        cin >> element >> price;
        hay[element] = price;
    }
    while (n--){
        int sum = 0;
        while (cin >> element && element != ".")
        {
            sum += hay[element];
        }
        cout << sum << "\n";
    }
    return 0;
}