#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    while(cin >> n){
        vector<int> a(n) , check(n , 0);
        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 1; i < n; i++){
            int diff = abs(a[i] - a[i - 1]);
            if(diff > 0 && diff < n)check[diff] = 1;
        }  
        cout << (count(check.begin() + 1 , check.end() , 0) == 0 ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}