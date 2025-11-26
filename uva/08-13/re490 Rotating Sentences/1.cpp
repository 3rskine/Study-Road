#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> v; string s; int m = 0;
    while( getline(cin ,s) ){
        m = max(m , (int)s.size());
        v.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        for (int j = v.size() - 1; j >= 0 ; j--)cout << ((i < v[j].size()) ? v[j][i] : ' ');
    cout << "\n";
    }
    return 0;
}