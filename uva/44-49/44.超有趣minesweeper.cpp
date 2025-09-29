#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n , m , cases = 0;
    char unit;
    
    while (cin >> n >> m, n || m)
    {
        int G[102][102] = {0};
       for (size_t i = 1; i <= n; i++) for (size_t j = 1; j <= m; j++)
       {
            cin >> unit;
            if(unit == '*'){
                G[i][j] -= 69;
                for (size_t y = i - 1; y <= i + 1; y++) for (size_t x = j - 1; x <= j + 1; x++)
                {
                    G[y][x]++;
                }
            }
       }

       cout << (cases ? "\n" : "") << "Field #" << ++cases << ":\n";

       for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++){
            G[i][j] >= 0 ? cout << G[i][j] : cout << "*";

       }
       cout << "\n";
    }  
    }
    return 0;
}