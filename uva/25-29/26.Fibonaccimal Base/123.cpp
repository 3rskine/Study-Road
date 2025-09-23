#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
// ===== Step 1: 產生 Fibonacci 數列 =====
    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(2);

    while(fib.back() < 100000000){
        size_t n = fib.size();
        fib.push_back (fib[n-1] + fib[n-2] );
    }
// ===== Step 2: 讀取 =====
    int N;
    cin >> N;
    while(N--){
        long long number;
        cin >> number;
        long long orignal = number;

 // ===== Step 3: 將數字轉成 Fibonaccimal base =====
        string fibbase = "";
        bool startOutputZero = 0;

        for (int i = (int)fib.size() - 1; i > -1; i--)
        {
            if(fib[i] <= number){
                startOutputZero = 1;
                fibbase += '1';
                number -= fib[i];
            }
            else if (startOutputZero) fibbase += '0';
        }

        cout << orignal <<" = " << fibbase <<" (fib)\n";
    }

}