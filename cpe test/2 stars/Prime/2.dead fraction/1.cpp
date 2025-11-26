#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd (ll a , ll b){
   return (b == 0) ? a : gcd(b , a % b);
}

int main(){
    string s;
    while(cin >> s){
        if(s == "0") break;
        string digit = s.substr(2 , s.size() - 5);
        int diglen = digit.size();
        ll wholenum = stoll(digit);

        vector<ll>pow10(diglen+1 , 1);
        for (int i = 1; i <= diglen; i++)pow10[i] = pow10[i-1] * 10LL;
        
        ll bestnum = 0, bestde = LLONG_MAX; 
        for (int i = 1; i <= diglen; i++){  // i = how many infin num
            ll prefix = (i == diglen) ? 0 : stoll(digit.substr(0 , diglen - i));
            ll numerator = wholenum - prefix;
            ll denomi = (pow10[i] - 1) * (pow10[diglen - i]);
            ll g = gcd(llabs(numerator) , denomi);
            numerator /= g; denomi /= g;
            if(denomi < bestde){
                bestde = denomi; bestnum = numerator;
            }
        } 
        cout << bestnum << "/" << bestde << "\n";
    }
    return 0;
}