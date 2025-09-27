#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int N;
    while (cin >> N && N != 0)
    {
        long long G = 0;
        for (size_t i = 1; i < N; i++)
        {
            for (size_t k = i+1; k <= N; k++)
            {
                G += __gcd(i , k);
            }
            
        }
        cout << G <<'\n';
        
    }
    
    return 0;
}
