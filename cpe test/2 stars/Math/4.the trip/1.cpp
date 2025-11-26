#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    while(cin >> n){
        if(n == 0)break;
        vector<long long>person(n);
        long long sum = 0;
        for (int i = 0; i < n; i++){
            string s; cin >> s;
            size_t p = s.find('.');
            long long dollars = 0;
            int centpart = 0;
            if(p == string::npos){
                dollars = stoll(s);
                centpart = 0;
            }
            else{
                if(p > 0)dollars = stoll(s.substr(0 , p));
                string frac = s.substr(p+1);
                if(frac.size() < 2)frac += string(2 - frac.size() , '0');
                centpart = stoi(frac);
            }
            person[i] = dollars * 100 + centpart;
            sum += person[i];
        } 
        long long low = sum /n; 
        long long  high = low + !((sum% n) == 0); 
        long long givedown = 0, giveup = 0;
        for(long long x: person){
            if(x > high) givedown += x - high;
            if(x < low) giveup += low - x;
        }
        long long res = max(givedown , giveup);
        cout << "$" << (res / 100) << "." << setw(2) << setfill('0') << (res % 100) << "\n";
    }
    return 0;
}