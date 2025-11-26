#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    while( cin >> n && n!= 0 ){
        int g =  1 + (n-1) % 9;
        cout << g <<endl;
    }
    return 0;
}