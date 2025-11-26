#include <bits/stdc++.h>
using namespace std;
int main(){
    char c,s[]=
    "1234567890-="
    "qwertyuiop[]\\"
    "asdfghjkl;'"
    "zxcvbnm,./";
    while (cin.get(c))
    {
        c = (tolower(c));
        char *p = strchr(s,c);
        (p) ? cout << *(p-2) : cout << c ;
    }
    return 0;
}