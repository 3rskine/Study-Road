#include <bits/stdc++.h>
using namespace std;
int main (){
    int a;
    int m , n;
    cin >> a;
    for(int casenum = 1 ; casenum <= a ; casenum++ ){       
    cin >> m >> n;

        int sum = 0;
        for(int o = m ; o <= n ; o++){
            if(o % 2 == 1){
                sum += o;
            }
            
        }
        cout << "Case " << casenum << ": " << sum << endl;
}
    return 0;
}