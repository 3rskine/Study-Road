#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<int> arr(n);
        for(int i=0 ; i < n ; i++) cin>> arr[i];

        vector<bool> sta(n , 0);
        for(int i= 1; i < n ; i++){
            int dif = abs(arr [i]-arr[i-1]);
            if (dif < n)
            {
                sta[dif] = 1;
            }
            }
        
        
        bool check = 1;
        for (int i = 1; i < n; i++) {
            if (!sta[i])
            {
                check=0;
            }
            
        }
cout<< (check? "Jolly\n" : "Not jolly\n");


}
return 0;
}