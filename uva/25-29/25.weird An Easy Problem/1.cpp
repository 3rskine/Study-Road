#include <bits/stdc++.h>
using namespace std;

// 將字元轉成對應數值
int charToVal(char c){
    if('0' <= c && c <= '9') return c - '0';
    if('A' <= c && c <= 'Z') return c - 'A' + 10;
    if('a' <= c && c <= 'z') return c - 'a' + 36;
    return 0; // 非法字符
}

int main(){
    string s;
    while(cin >> s){
        int sum = 0;
        int maxDigit = -1;
        for(char c : s){
            int val = charToVal(c);
            sum += val;
            maxDigit = max(maxDigit, val);
        }

        // base 至少要大於最大位數
        int base = max(2, maxDigit + 1);
        bool found = false;
        while(base <= 62){
            if(sum % (base - 1) == 0){ // 利用性質檢查整除
                found = true;
                break;
            }
            base++;
        }

        if(found) cout << base << "\n";
        else cout << "such number is impossible!\n";
    }
}
