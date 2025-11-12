#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int t;cin >> t;
    while (t--)
    {
        int digit; cin >> digit;
        vector<int> A(digit);
        vector<int> B(digit);
        for (size_t i = 0; i < digit; i++)
        {
            char a , b;
            cin >> a >> b;
            A[i] = a - '0';
            B[i] = b - '0';
        }
        string result(digit,'0');
        int carry = 0;
        for (int k = digit - 1; k >= 0; k--)
        {
            int sum = A[k] + B[k] + carry;
            result[k] = '0' + (sum % 10);
            carry = sum / 10;
        }
        cout << result << endl;
        if(t > 0) cout << "\n";
    }
    
    return 0;
}