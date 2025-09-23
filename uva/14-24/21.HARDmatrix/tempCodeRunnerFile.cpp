#include <bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n ;
    cin >> n;
    for(int times = 1 ; times <= n ; times++){
        int N;
        string ignore;
        cin >> ignore >> ignore >> N; //讀 "N = 3"

        vector<vector<long long>> M (N ,vector<long long>(N)); /*if(N ,vector<long long>(n)) 且 N=3 , n = 4 則M = { [0, 0, 0, 0] , [0, 0, 0, 0] , [0, 0, 0, 0] }*/
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> M[i][j];
                
        bool isSYM = 1;
        for (int i = 0; i < N && isSYM; i++) {
            for (int j = 0; j < N && isSYM; j++) {
                if(M[i][j] != M[N-1-i][N-1-j] || M[i][j] < 0) isSYM = 0;
            }
        }

        cout << "Test #" << n << ": ";
        cout <<(isSYM? "Symmetric." : "Non-symmetric." ) <<endl;                                                                                       
    }
    return 0;
}