#include <bits/stdc++.h>
using namespace std;
bool isPrime (int k){
    int code = -1;
    if(k < 2) code = 0;
    else if(k == 2) code = 1;
    else if (k % 2 == 0) code = 0; // 偶數不是質數
    else code = 2;             // 其他情況，需要用迴圈檢查

    switch (code)
    {
    case 0:
            return 0;
    case 1:
            return 1;
    case 2:{
            int limit = sqrt(k);
            for (size_t i = 3; i <= limit; i += 2)
            {
                if (k % i == 0) {
                    return 0; 
                }
            }
            return 1;           
    }
    }
    return 0;
}

int revTheNumber (int n){
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main() {
    int N;
    while (cin >> N)
    {
        if(!isPrime(N)){
            cout << N << " is not prime.\n";
        }
        else{
            int rev = revTheNumber(N);
            if(rev != N && isPrime(rev))
            {cout << N << " is emirp." << "\n";}
            else {cout << N << " is prime." << "\n";}
        }
    }
    return 0;
}