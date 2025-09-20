#include <bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int a,b;
    while(cin >> a >>b){
    if(a == 0 && b == 0){
        cout << "0" <<endl;
    } 
    else {
        cout << 2*a*b<<endl;
    }
    }
    return 0 ;

}