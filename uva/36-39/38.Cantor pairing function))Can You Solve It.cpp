#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll steps(ll x, ll y){
    ll sum = x + y;
    return sum * (sum + 1) /2 + x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    for (size_t i = 1; i <= T; i++)
    {
        ll x1,y1,xx,yy;
        cin >> x1 >> y1 >> xx >> yy;
        ll stepa = steps(x1 , y1);
        ll stepb = steps(xx , yy);

        ll res = abs(stepa - stepb);
        cout << "Case " << i << ": " << res << '\n';
    }
    

    return 0;
}