#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    while (cin >> T)
    {
        vector<int> numlist(T);
        for (size_t i = 0; i < T; i++) cin >> numlist[i];
        
        sort(numlist.begin() , numlist.end());

        int medianodd, medianeven;

        medianodd = numlist[T / 2];
        medianeven = numlist[(T - 1) / 2];

        int count_med = 0;
        for (size_t i = 0; i < T; i++) if(numlist[i] == medianodd || numlist[i] == medianeven) count_med++;
        
        
        int possible_A = 1;
        if(T % 2 == 0){
            int low = numlist[T / 2  -  1];
            int high = numlist[T / 2];
            possible_A = high - low + 1; // 從小中位數 到 大中位數 之間的整數有幾個(設T為偶數位)
        }
        cout << medianeven << " " << count_med << " " << possible_A << "\n";
    }
    
    return 0;
}