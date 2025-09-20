#include <bits/stdc++.h>
using namespace std;
bool isSquare (int o){
    int root = sqrt(o);
    return root * root == o; //若為square則回傳1反之0
}
int main (){
    int m , n ;
    
    while ( cin >> m >> n ){
        if( m == 0 && n == 0 )break;
        int squCount = 0 ;
        for (size_t i = m ; i <= n ; i++ ){
            if(isSquare(i)) squCount++;
        }
        cout << squCount <<endl;
    }
    return 0;
}