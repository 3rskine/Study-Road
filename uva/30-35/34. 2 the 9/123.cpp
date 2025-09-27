#include <bits/stdc++.h>
using namespace std;
int main (){
    string n;
    while (cin >> n)
    {
        if(n == "0") break;

        long long sumOfdigit = 0;
        for (char digit : n) sumOfdigit += digit - '0';

        if(sumOfdigit % 9 != 0){
             cout << n << " is not a multiple of 9.\n" ;
        }
        else{
            int caltimes = 1;
            while (sumOfdigit >= 10)
            {
                int CurrentDigitSum = 0;
                while (sumOfdigit > 0)
                {
                    CurrentDigitSum += sumOfdigit % 10;
                    sumOfdigit /= 10;
                }
                sumOfdigit = CurrentDigitSum;
                caltimes++;
            }
            cout << n << " is a multiple of 9 and has 9-degree " << caltimes << "." << "\n";
        }
        

    }
    return 0;
    
}