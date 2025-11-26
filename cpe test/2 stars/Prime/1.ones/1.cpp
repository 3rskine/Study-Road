#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; while(cin>>n){
        if(n == 0)break;
        int rem = 0, len = 0;
        do
        {
            rem = (rem * 10 + 1) % n;
            len++;
        } while (rem != 0);
        cout << len << "\n";
    }
    return 0;
}