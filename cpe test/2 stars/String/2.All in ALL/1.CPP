#include <bits/stdc++.h>
using namespace std;
int main(){
    string s , t;
    while (cin >> s >>t)
    {
        int i = 0 , j = 0;
        while (i < s.size() && j < t.size())
        {
            if(s[i] == t[j]) i++;
            j++;
        }
        cout << (i == s.size() ? "Yes" : "No") << "\n";
    }
    return 0;
}