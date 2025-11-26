#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ,casenum = 0;
    while(cin >> n){
        int arr[n] , listt[20002] = {};
        for (int i = 0; i < n; i++)cin >> arr[i];

        bool isb2 = 1;
        if(arr[0] < 1) isb2 =0;
        for (int i = 0; i < n-1 && isb2; i++)if(arr[i] > arr[i+1] || arr[i+1] < 1) isb2 = 0; 
        for (int i = 0; i < n && isb2; i++)for (int j = i; j < n && isb2; j++){
            int index = arr[i] + arr[j];
            listt[index]++;
        }
        for (int i = 0; i <= 20000 && isb2 ; i++)if(listt[i] > 1)isb2 = 0;
        cout <<"Case #"<< ++casenum << ":" << ((isb2 == 1) ? " It is a B2-Sequence.\n\n" : " It is not a B2-Sequence.\n\n");
    }
    return 0;
}