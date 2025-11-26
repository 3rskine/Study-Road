#include<bits/stdc++.h>
using namespace std;
int main(){
    int count[300] = {} , len = 0;
    char c;
    while (cin.get(c)){
        if(isalpha(c)){
            c = toupper(c);
            len++;
            count[c]++;
        }
    }
    
    while (len--)
    {
        for (c = 'A'; c <= 'Z' ; c++)
        {
            if(count[c] == 0) continue;
            if(count[c] == len) cout << c << " " << count[c] << endl;
        }
    }
    return 0;
}