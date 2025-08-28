#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
    string a,b;

    while (getline(cin,a) && getline(cin,b)){
        int countA[26] = {0},countB[26] = {0};

        for( char unita : a){
            countA[unita - 'a']++;
        }
        for( char unitb : b){
            countB[unitb - 'a']++;
        }
        string result;
        for(int i = 0; i < 26 ; i++){
            int common = min(countA[i] , countB[i]);
            result += string(common , 'a' + i);
        }
        cout << result <<endl;
    }
    return 0 ;
}