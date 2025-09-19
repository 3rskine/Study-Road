#include <bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    long long s,d;
    while (cin >> s >>d)
    {
        long long low = 0, high = 2000000000LL;
        while(low < high){
            long long mid = (high + low) /2;
            __int128 sum= (__int128)(mid+1)*s +(__int128)(mid)*(mid+1)/2;
            if (sum >= d) high = mid;
            else low = mid+1;
        }
        cout << s + low <<endl;
    }
    return 0;
    
}