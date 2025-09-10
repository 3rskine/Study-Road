#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main (){
    string is11 ;
        while (cin >> is11&& is11 != "0")
        {
            int odd=0 , even =0;
            for (size_t i = 0; i < is11.length(); i++)
            {
                int record = is11[i] - '0';
                
                if (i%2 == 1)
                {
                    odd += record;
                }else{
                    even += record;
                }
                
            }
            int dif = abs( odd - even);
            if (dif%11 == 0)
            {
            cout << is11 << " is a multiple of 11." << endl;
            }
            else{
            cout <<is11 << " is not a multiple of 11." << endl;
            }
        
        }
        return 0;
        
}