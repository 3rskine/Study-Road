#include <iostream>
using namespace std;

int ALPHA (int s){
        int count = 1;
        while( s!= 1){
            if(s % 2 == 1){
            s = 3*s+1;
            }
            else{
            s = s/2;
            }
        count ++;
        }
        return count;
}
//define a funtion to compute the times of cycle

int main(){
    int i , j;

        while (cin >> i >> j){
            int P = min(i,j);
            int Q = max(i,j);
            
                int max = 0; //def the number with most times of cycle.
                for (int a = P ; a<=Q ; a++ )
                {
                    int cycletimes = ALPHA(a);
                    if(cycletimes > max){
                    max = cycletimes;
                    }
                }
            cout << i << " " << j <<" " <<max << endl;
            }
    return 0;
}