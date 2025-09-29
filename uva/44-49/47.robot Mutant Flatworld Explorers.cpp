#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
map<char, int> dir2idx = {{'N',0}, {'E',1}, {'S',2}, {'W',3}};
char idx2dir[4] = {'N','E','S','W'};

int main(){
    int bordX , bordY ;
    cin >> bordX >> bordY;

    set<pair<int,int>> scent;

    int spawnX , spawnY;
    char spawnFace;
    string cmd;

    while(cin >> spawnX >> spawnY >> spawnFace){
        cin >> cmd;
        int nowFace = dir2idx[spawnFace];
        bool isLOSE = 0;

        for (char attack : cmd)
        {
            if(attack == 'L') nowFace = (nowFace + 3) % 4;
            else if(attack == 'R') nowFace = (nowFace + 1) % 4;
            else if(attack == 'F'){
                int nowX = spawnX + dx[nowFace];
                int nowY = spawnY + dy[nowFace];

                if(nowX < 0 || nowY < 0 || nowX > bordX || nowY > bordY){
                    if(scent.count({spawnX , spawnY})) continue;  // 只看格子
                    isLOSE = 1;
                    scent.insert({spawnX , spawnY});
                    break;
                }
                else{
                    spawnX = nowX;
                    spawnY = nowY;
                }
            }
        }

        cout << spawnX << " " << spawnY << " " << idx2dir[nowFace];
        if (isLOSE) cout << " LOST";
        cout << "\n";
    }
    return 0;
}