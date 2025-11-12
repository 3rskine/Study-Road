#include <bits/stdc++.h>
using namespace std;

string BIG(string a , string b){
    int lena = a.size(); int lenb = b.size();
    vector<int>result(lena+lenb , 0);

    for (int i = lena - 1; i >= 0; i--)for (int j = lenb - 1; j >= 0; j--){
        int mulnum = (a[i] - '0') * (b[j] - '0');
        int sum = result[i+j + 1] + mulnum;
        result[i+j + 1] = sum % 10;
        result[i+j] += sum / 10;
    }
    string thenum;
    bool stillzero = 1;
    for(int digit : result){
        if(stillzero && digit == 0)continue;
        stillzero = false;
        thenum += (digit + '0'); // digit is int, and it should be turn into char
    }

    return thenum.empty() ? "0" : thenum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string X, Y;
    while (cin >> X >> Y) {
        cout << BIG(X, Y) << "\n";
    }
    return 0;
}