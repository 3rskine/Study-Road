#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    int casenum = 1;
    while (cin >> n){
        vector<int> seq(n);
        for (int i = 0; i < n ; i++){
            cin >> seq[i];
        }
    

    bool isB2 = 1;
    if(seq[0] < 1) isB2 = 0;
    for (size_t i = 1 ; i < n && isB2 ; i++)
    {
        if(seq[i] <= seq[i-1]) {
        isB2 = 0;
    }
    }

    if(isB2){
        set<int> sums;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i; j < n; j++)
            {
                int sum = seq[i] + seq[j];
                if(sums.count(sum)){
                    isB2 = 0;
                    break;
                }
                sums.insert(sum);
            }
        }
    }
    cout << "Case #" << casenum++ << ": ";
        if (isB2) cout << "It is a B2-Sequence.\n";
        else cout << "It is not a B2-Sequence.\n";
    cout << "\n";
    }
    return 0 ;
}