#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string a;
    while (cin >> a && a!="0"){
        int odd =0 , even =0;
        for (size_t i = 0; i < a.length() ; i++){
            int K = a[i]-'0'; //這個字串在這個位置的數字是多少
            if ( i%2 == 1){
                odd += K;
            } else {
                even += K;
            }
        }

    int  dif = abs (odd - even);
        if ( dif % 11 == 0){
        cout << a << " is a multiple of 11." << endl;
        }
        else{
        cout << a << " is not a multiple of 11." << endl;
        }
    
    }
}