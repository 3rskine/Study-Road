#include <bits/stdc++.h>
using namespace std;
string addbig(string a , string b){
    string res = "";
    int inda = a.length() - 1, indb = b.length() - 1 , carry = 0;
    while (inda >= 0 || indb >= 0 || carry > 0)
    {
        int nowdigita = (inda >= 0) ? a[inda] - '0' : 0;
        int nowdigitb = (indb >= 0) ? b[indb] - '0' : 0;

        int nowdigitsum = nowdigita + nowdigitb + carry;
        carry = nowdigitsum / 10;
        nowdigitsum %= 10;

        res.push_back(char(nowdigitsum + '0'));
        inda--;
        indb--;
    }
    reverse(res.begin() , res.end());
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    vector<string> fibtable(5001);
    fibtable[0] = "0";
    fibtable[1] = "1";

    for (int i = 2; i < 5001; i++)
    {
        fibtable[i] = addbig(fibtable[i-2] , fibtable[i-1]);
    }
    int inputnum;
    while (cin >> inputnum)
    {
        cout <<  "The Fibonacci number for "  << inputnum
        << " is " << fibtable[inputnum] << "\n";
    }
    return 0;
}