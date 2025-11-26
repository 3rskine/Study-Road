#include <bits/stdc++.h>
using namespace std;

int main(){
    int s; cin >> s;
    int casenum = 0;
    while(s--){
        long long a,b, sum =0;cin >> a >> b;
        for (long long start = a; start <= b ; start++) if(start % 2 == 1)sum += start;
        cout << "Case "<< ++casenum << ": "  << sum <<endl;
    }
    return 0;
}