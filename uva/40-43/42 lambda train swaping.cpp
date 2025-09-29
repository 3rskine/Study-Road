#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
    {
        int L; cin >> L ;
        vector<int> train(L);
        for (size_t i = 0; i < L; i++) cin >> train[i];

        int swaptimes = 0;
        for (size_t i = 0; i < L; i++)
        {
            for (size_t j = 0; j < L-1; j++)
            {
                if(train[j] > train[j+1]) {
                    swap(train[j],train[j+1]);
                    swaptimes++;
                }
            }
            
        }
        cout << "Optimal train swapping takes " << swaptimes << " swaps.\n";
        
    }
    


    return 0;
}