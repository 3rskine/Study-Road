#include <bits/stdc++.h>
using namespace std;

string picknum (const string text){
    string digit;
    for(char c : text){
        if(isdigit(c))digit += c;
    }
     return digit;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, run = 1;
    while(cin >> n && n != 0){
        cin.ignore();
        string criteria, usertext , tmpline;
    
        for (size_t i = 0; i < n; i++){
            getline(cin , tmpline);
            criteria += tmpline;
            criteria += "\n";
        }

        cin >> m;
        cin.ignore();
        for (int j = 0; j < m; ++j) {
            getline(cin, tmpline);
            usertext += tmpline;
            usertext += '\n';
        }

        cout << "Run #" << run++ << ": ";
        (criteria == usertext) ? cout << "Accepted\n" : (picknum(criteria) == picknum(usertext)) ?  cout << "Presentation Error\n" : cout << "Wrong Answer\n" ;
    }
    return 0;
}