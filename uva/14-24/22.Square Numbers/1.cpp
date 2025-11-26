#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    while(cin >> a >> b){
        int cnt = 0 ;
        if(a == 0 && b == 0) break;
        for (int i = 1; i <= sqrt(b) ; i++)if( i*i <= b && i*i >= a) cnt++;
        cout << cnt << endl;
    }
    return 0;
}