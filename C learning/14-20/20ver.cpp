#include <bits/stdc++.h>
using namespace std;

int main(){
    string t;
    getline(cin , t);
    int n = t.length();
    int mostleft = 0 , maxl = 0;
    for (int i = 0; i < n ; i++) for (int iseven = 0; iseven <= 1 ; iseven++){
        int L = i, R = i + iseven;
        while(L>= 0 && R < n && t[L] == t[R]){
            L--; R++;
        }
        int opstart = L + 1;
        int opend = R - 1;
        int textlen = opend - opstart + 1;

        if(textlen > 0){
            if(t[opstart] == ' ' && t[opend] == ' '){opstart++; opend--; textlen-= 2;}
            if(textlen > 0 && (textlen > maxl || (textlen == maxl && opstart < mostleft)))
            {
                mostleft = opstart;
                maxl = textlen;
            }
        }
    }  
    for (int i = 0 ; i < maxl ; i++)cout << t[i + mostleft];
    cout << endl;
    return 0;
}