#include <bits/stdc++.h>
using namespace std;

int mygcd (int a , int b){
    while ((a %= b) && (b %= a));
    return a + b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int N; cin >> N;
    string s1 , s2;
 
    for (size_t cases = 1; cases <= N; cases++)
    {
        cin >> s1 >> s2;
        int twobase1 = 0 , twobase2 = 0;
        for (size_t i = 0; i < s1.size(); i++)
        {
            twobase1 *=  2;
            twobase1 += s1[i] - '0';
        }
        for (size_t i = 0; i < s2.size(); i++)
        {
            twobase2 *=  2;
            twobase2 += s2[i] - '0';
        }
        
        cout << "Pair #" << cases;
        mygcd (twobase1 , twobase2) > 1 ? cout << ": All you need is love!\n" : cout << ": Love is not all you need!\n";
    }
    

    return 0;
}