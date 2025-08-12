#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    string a, b;

    while(1){
        cin>> a >>b;
        if(a=="0"&&b=="0") break;
        
        reverse( a.begin(),a.end() );
        reverse( b.begin(),b.end() );
        
        int addit= 0; //若進位為1 -> 8+9=17 (十位+1)
        int num=  0; //進位次數
        int length = max(a.size() , b.size() );


        for (int i = 0; i< length ; i++)
        {
            int da = (i < (int)a.size()) ? (a[i] - '0') : 0;
            int db = (i < (int)b.size()) ? (b[i] - '0') : 0;

            int sum = da + db + addit;
            if( sum > 9)
            {
             addit = 1;

             num ++;
            }
            else
            {
            addit = 0;
            }


        }
        
        if ( num == 0){
        cout << "No carry operation." << endl;
        }
        else if ( num == 1) {
        cout << num <<" carry operation." << endl;
        }        
        else {
        cout << num <<" carry operations." << endl;
        }
    }
    return 0;
}