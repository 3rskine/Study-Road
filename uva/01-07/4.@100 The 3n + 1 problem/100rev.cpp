#include <iostream>
using namespace std;
int function(int a){
    int count = 1;
    while( a!=1){
        if(a%2 == 1){
        a = 3*a+1;
        count++;
        }else{
        a = a/2;
        count++;
        }
    }
    return count; //輸出count值
}

    int main(){
    int a = 0 , b = 0; 
       while (cin>> a >>b)
       {
        int A = min(a,b);
        int B = max(a,b);

        int theGreatestNum = 0;
        for(int i = A; i<=B ; i++){
            int theFirstNumOfCountTimes = function(i);
            if(theFirstNumOfCountTimes > theGreatestNum){
        theGreatestNum = theFirstNumOfCountTimes;
        }
        
        }
        cout<< a << " " << b << " " << theGreatestNum << endl;
       }
       return 0;

    }