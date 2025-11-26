#include <bits/stdc++.h>
using namespace std;
int main(){
    string a ,b;
    while( getline(cin , a) && getline(cin , b) ){
        int ca[26]{} , cb[26]{};
        for(char ch : a) ca[ch - 'a']++;
        for(char ch : b) cb[ch - 'a']++;
        string s;
        for (int i = 0; i < 26; i++) s += string(min(ca[i] , cb[i]) , 'a' + i);
        cout << s <<"\n";
    }
    return 0;
}