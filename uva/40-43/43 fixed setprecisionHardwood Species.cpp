#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T; cin >> T;
    string line;
    cin.ignore();

    while(T--){
        map<string , int> treelist;
        int total = 0;
        while (getline(cin , line) && line.empty());
        
        do { treelist[line]++; total++; } 
        while (getline(cin , line) && !line.empty());

        for (auto &[name , percentage] : treelist)
        {
           cout << name << " " << fixed <<setprecision(4) << (double)percentage * 100.0 / total << endl;
        }
        
        if(T) cout << "\n";
    }
    return 0;
}