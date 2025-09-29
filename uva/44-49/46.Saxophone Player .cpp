#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    map<char , vector<int>> fingertable;
    fingertable['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
    fingertable['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    fingertable['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    fingertable['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
    fingertable['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    fingertable['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    fingertable['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    fingertable['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    fingertable['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    fingertable['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    fingertable['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
    fingertable['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    fingertable['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    fingertable['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

    int t; cin >> t;
    cin.ignore();
    string song;

    while (t--)
    {
        getline(cin , song);
        int count[11] = {0};
        bool isPressing[11] = {0};

        for (size_t i = 0; i < song.size(); i++) for (size_t j = 1; j <= 10; j++)
        {
            if(fingertable[song[i]][j]){
                if(isPressing[j]) continue;
                else{
                    isPressing[j] = 1;
                    count[j]++;
                }
            }
            else isPressing[j] = 0;
        }
        for (size_t i = 1; i <= 10; i++) cout << count[i] << (i == 10 ? "\n" : " ");
    }
    return 0;
}