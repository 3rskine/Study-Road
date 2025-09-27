#include <bits/stdc++.h>
using namespace std;
int main() {
    //N 被除數，M 除數 , if N = 125 , M = 5 (注意 N = 1 而 M為任意數的情況)
    long long N , M;
    while (cin >> N >> M)
    {
        if(M <= 1 || N <= 1) {
            cout<<"Boring!\n";
            continue;
        }

        vector<long long> beenDiv;
        long long current = N;
        beenDiv.push_back(current);
    
        bool isBoring = 0;
        while (current > 1)
        {
            if(current % M != 0){
                isBoring = 1;
                break;
            }
            current /= M;
            beenDiv.push_back(current);
        }


        if(isBoring == 0 && current == 1){
            for (size_t i = 0; i < beenDiv.size(); i++)
            {
                cout << beenDiv[i];
                if(i < beenDiv.size() - 1) cout << " ";
            }
            cout << "\n";
        }
        else cout <<"Boring!\n";
    }
    return 0;
    
}