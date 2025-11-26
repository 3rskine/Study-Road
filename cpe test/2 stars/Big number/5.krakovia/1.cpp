#include <bits/stdc++.h>
using namespace std;

string addbig(string a , string b){
    string res;
    int carry = 0;
    int lena = a.size(), lenb = b.size();
    int maxlen = max(lena,lenb);
    for (int i = 0; i < maxlen; i++)
    {
        int digita = (i < lena) ? (a[lena - i - 1] - '0') : 0;
        int digitb = (i < lenb) ? (b[lenb - i - 1] - '0') : 0;
        int sum = digita + digitb + carry;
        res.push_back((sum % 10) + '0');
        carry = sum/10;
    }
    if(carry)res.push_back(carry + '0');
    reverse(res.begin() , res.end());
    return res;
}
string quobig(string a , int b){
    string res;
    long long current = 0;
    for (char c : a){
        current = current * 10 + (c - '0');
        res.push_back((current / b) + '0');
        current %= b;
    }
    int pos = 0;
    while (pos < res.size() - 1 && res[pos] == '0') pos++;
    return res.substr(pos);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n , f;
    int bill = 1;
    while (cin >> n >> f)
    {
        if(n == 0 && f == 0) break;
        string total = "0";
        for (int i = 0; i < n; i++)
        {
            string val;
            cin >> val;
            total = addbig(total , val);
        }
        string aver = quobig(total , f);
        cout << "Bill #" << bill << " costs " << total << ": each friend should pay " << aver <<"\n\n";
    bill++;    
    }
    return 0;
}