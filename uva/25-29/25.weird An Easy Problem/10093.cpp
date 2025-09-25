#include <bits/stdc++.h>
using namespace std;
int charToValue (char c){
    if('0' <= c && c <= '9') return c -'0';
    if('A' <= c && c <= 'Z') return c -'A'+10;
    if('a' <= c && c <= 'z') return c -'a'+36;
    return -1;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    while (cin >> s)
    {
        int MaxDegit = -1;
        int sum = 0;
        for(char c : s){
            int val = charToValue(c);
            if(val == -1) continue;

            MaxDegit = max(MaxDegit , val);
            sum += val;
        }

        int base = max(2,MaxDegit+1);
        bool foundit = 0;
        while (base <= 62){
            if(sum % (base - 1) == 0) {
                foundit = 1;
                break;
            }
            base++;
        }

        if(foundit)
            cout << base <<endl;
        else
            cout <<"such number is impossible!" <<endl;
    }   
    return 0;
}