#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    string a, b;
       
        while(1){
        
         cin>> a >> b ;
         if(a == "0" && b == "0") break;
        reverse (a.begin(),a.end());
        reverse (b.begin(),b.end());
        int Carryvalue = 0;
        int CarryTimes = 0;
        int length = max(a.size() , b.size() );
            for (int i = 0; i < length; i++)
            {
            //記錄字串內的數字（a[i] - '0'）
                int na = (i < (int)a.size()) ? (a[i]- '0') : 0;
                int nb = (i < (int)b.size()) ? (b[i]- '0') : 0;
                int sum = na + nb + Carryvalue;
                if( sum > 9 ){
                Carryvalue = 1;
                CarryTimes++;
                }else{
                Carryvalue = 0;
                }
            }
         if(CarryTimes == 0){
            cout << "No carry operation." << endl;
        }else if(CarryTimes == 1) {
            cout << CarryTimes << " carry operation." << endl;
        }else{
            cout << CarryTimes << " carry operations." << endl;
        }

        }
        return 0;

}