#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;cin >>s;
    while(s--){
        long long a , b;
        cin >>a >> b;
        int fi , se;
        if( (a+b) % 2 == 1) {cout << "impossible" << endl; continue;}
        fi = (a + b) / 2;
        se = fi - b;
        if(se >= 0) cout << fi << " " << se << endl;
        else cout << "impossible" << endl;
    }
    return 0;

}