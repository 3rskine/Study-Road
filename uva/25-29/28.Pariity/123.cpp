#include <bits/stdc++.h>
using namespace std;

int countones(long long k){
    int count = 0;
    while (k) {
        if (k & 1) count++;  
        k >>= 1;             
    }
    return count;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    long long orig;
    while (cin >> orig && orig != 0)
    {   
        string twosbase = "";
        long long meat = orig;
        while (meat > 0)
        {
            twosbase = char (('0' + meat % 2)) + twosbase;
            meat /= 2;
        }

        int howmanyone = countones(orig);
        cout <<"The parity of " << twosbase << " is " << howmanyone <<" (mod 2).\n";
    }
    return 0;
}