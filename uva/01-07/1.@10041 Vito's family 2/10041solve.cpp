#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int a;
    cin >> a ;

        while(a--)
        {
            int K;
            cin >> K;

            vector<int> relat(K);

            for(int i=0; i<K ; i++){
            cin >> relat[i];
            }
            sort(relat.begin() , relat.end() );

            int med;
            med = relat[ K/2 ];

            int sum_dis = 0;
            for(int i=0; i<K ; i++)
            {
                sum_dis += abs(relat[i] - med);

            }
            cout << sum_dis<<endl;
        }
        return 0 ;
}