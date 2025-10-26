#include <bits/stdc++.h>
#define LOCAL
using namespace std;

const int maxx = 120;

int t , q , n , m;
int direction[4][2] = {
    {0, 1},   // 右
    {1, 0},   // 下
    {0, -1},  // 左
    {-1, 0}   // 上
};
string graph [maxx];

int isvalid(int x , int y){
    if(x >= 0 && x < m && y >= 0 && y < n) return 1; //判斷此位置是否超出邊界
    return 0;
}
int find_square(int x , int y){
    int r = 1;
    int center_char = graph[x][y];
    int isbigger = 1;

    while (isbigger)
    {
        r+=2;
        int newX = x - r/2 , newY = y - r/2;

        for(int i =0 ; i < 4 ; i++) for (int j = 0; j < r-1; j++)
        {
            newX += direction[i][0];
            newY += direction[i][1];
            if(!isvalid (newX , newY) || graph[newX][newY] != center_char){
                isbigger = 0; break;
            }
        }
         if(isbigger == 0) break; //如果無法通行則離開
    }
    return r-2;
}

int main(){
    #ifdef LOCAL
        freopen("in1.txt", "r" ,stdin);
        freopen("out.txt", "w" ,stdout);
    #endif
        cin >> t;
        while (t--)
        {
            cin >> m >> n >> q;
            for(int i = 0; i < m; i++) cin >> graph[i]; //輸入地圖
            cout << m << ' ' << n << ' ' << q << '\n'; //輸出地圖資訊
            int x , y;
            while (q--)
            {
                cin >> x >> y;
                cout << find_square(x , y) << endl;
            }
        }
        return 0;
}