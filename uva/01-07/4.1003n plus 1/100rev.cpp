#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    int cnt = 1;
    while (n != 1)
    {
        if(n % 2 == 1) n = 3*n +1;
        else n /= 2;
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a,b;
    while (cin >> a >> b)
    {
        int begin = min(a,b);
        int end = max(a,b);;
        int maxcnt = 0;
        for (int i = begin; i <= end; i++) maxcnt = max(maxcnt , fun(i));
        
        cout << a << " " << b << " " << maxcnt << "\n";
    }
    return 0;
}