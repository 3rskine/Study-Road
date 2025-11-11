#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    cin.ignore();
    string s; 
    while (getline(cin , s) && n > 0)
    {
        n--;
        string p;
        bool islegal = 1;
        for(char c : s){
            if (c == '(' || c == '[') {
                p.push_back(c);
            } else if (c == ')'){
                if(p.empty() || p.back() != '('){islegal = 0; break;}
                p.pop_back();
            } else if (c == ']'){
                 if (p.empty() || p.back() != '['){islegal = false; break; }
                p.pop_back();
            }
        }
        if(!p.empty()) islegal = 0; //如果p不是空的，則不合法
        cout << (succ ? "Yes" : "No") << endl;
    }
    return 0;
}