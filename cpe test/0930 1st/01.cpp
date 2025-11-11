#include <bits/stdc++.h>
using namespace std;
int cnt(int k){
    int times = 1;
    while (k != 1)
    {
        times++;
        ( k % 2 == 1) ? k = 3*k + 1 :  k /= 2;
    }
    return times;
}
int main(){
    int a , b;
    while(cin >> a >> b){
        cout << a << " " << b << " ";
        int ini = min(a,b);
        int end = max(a,b);
        int maxtimes = -1;
        for (int i = ini; i <= end; i++) maxtimes = max(maxtimes , cnt(i));
        cout << maxtimes <<endl;
    }
    return 0 ;
}