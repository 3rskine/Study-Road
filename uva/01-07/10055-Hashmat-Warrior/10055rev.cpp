#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int main(){
vector<long long> troop(2, 0);
    while (1){

        for (int i = 0; i < troop.size(); i++)
        {
            if(!(cin>>troop[i])) return 0;
        }
        cout << abs(troop[0] - troop[1] ) <<endl;
    }
    return 0;
}