#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int ans[3000];
    int pd[3000] = {1};
    for (int i = 1; i <= 1000 ; i++)
    {
        for (int k = 0; k < 3000; k++)pd[k] *= i;
        for (int j = 0; j < 3000; j++)
        {
            pd[j+1] += pd[j] / 10;
            pd[j] %= 10;
        }
        for (int a = 0; a < 3000; a++) ans[i] += pd[a];
    }
    int n;
    while (cin >> n)cout << ans[n] << endl;
    return 0;
}