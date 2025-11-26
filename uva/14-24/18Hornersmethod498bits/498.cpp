#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    long long x;
    string coefLine;

    while( cin >> x){
        cin.ignore();
        getline(cin , coefLine);
        
        stringstream ss(coefLine);
        long long coefNum;
        vector<long long> coeflist;

        while(ss >> coefNum){
            coeflist.push_back(coefNum);
        }
        long long theHighDegree = coeflist.size() - 1;

        long long partResult = 0; 
        /*記錄每一小段的運算結果，
        注意要求的是導數，所以會是次方*該次方的係數 + 先前已經算出的部分解
        比如2x^3 +4x^2+5x+1就是 (((2x+4)x+5)x+1)
        一開始partResult是0 -> nowpow = 3 coeflist[coefindex] = 2
        partResult後紀錄的就是2x+4，x帶入，然後繼續算
        總之就是divide and conquer
        */                                       
        for(size_t coefIndex = 0 ; coefIndex < coeflist.size()-1 ; coefIndex++){
            long long nowPow = theHighDegree - coefIndex;
            partResult = x * partResult + nowPow * coeflist[coefIndex];
        }
        cout << partResult <<endl;
    }
    return 0 ;


}