#include <bits/stdc++.h>
using namespace std;
int main(){
    char c; int k = 0;
    while( cin.get(c) )cout << ((c == '"') ? ((++k % 2) ? "``" : "''" ) : string(1,c));    
    return 0;
}