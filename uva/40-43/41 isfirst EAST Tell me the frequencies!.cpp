#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string line;
    bool isfirst = 1;
    while (getline (cin , line))
    {
        int freq[128] = {0};
        for(char c : line) if(c != '\n' && c != '\r') freq[c]++;

        vector<pair<int , int>> list; //該字的ascii , 出現的times
        for (size_t i = 0; i < 128; i++) if(freq[i]) list.push_back({i,freq[i]});
        
        sort(list.begin() , list.end() , [](auto &a , auto &b){return a.second != b.second ? a.second < b.second : a.first > b.first;});

        if(!isfirst)cout << "\n"; isfirst = 0;
        for (auto &p : list)
        {
           cout << p.first << " " << p.second << "\n";
        }
        
    }
    
    return 0;
}