#include <bits/stdc++.h>
using namespace std;

int tser(char c){
    if('A' <= c && c <= 'Z') return c - 'A';
    if('a' <= c && c <= 'z') return c - 'a' + 26;
    if('0' <= c && c <= '9') return c - '0' + 52;
    if(c == '+') return 62;
    if(c == '/') return 63;
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    string line;
    string dataset;
    while (getline(cin , line))
    {
       for (char c : line)
       {
        if(c == '#'){
            if(dataset.empty()) return 0;
            string decode;
            int buffer = 0 , bit = 0;
            for(char ch : dataset){
                if(ch == '=') break;
                int val = tser(ch);
                if(val == -1)continue;
                buffer = (buffer << 6) | val;
                bit += 6;
                while(bit >= 8){
                    bit -= 8;
                    decode += char((buffer >> bit) & 0xFF);
                }
            }
            cout << decode << "#";
            dataset.clear();
        }
        else{
            dataset += c;
        }
       }
       
    }
    
    return 0;
}