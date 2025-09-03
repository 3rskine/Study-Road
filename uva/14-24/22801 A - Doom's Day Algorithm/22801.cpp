#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main (){
    int k;
    cin >> k;
    int base[13] = {0, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    while (k--){
        int M, D;
        cin >> M >> D;
        int diffofday = D - base[M];//實際日子 扣掉 某月的基準日
        int Cortvalu = (0+diffofday) % 7;
        if(Cortvalu < 0) Cortvalu+=7;
        cout<< week[Cortvalu];
    }
    return 0 ;

}