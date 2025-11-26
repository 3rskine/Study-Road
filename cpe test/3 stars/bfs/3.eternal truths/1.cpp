#include<bits/stdc++.h>
using namespace std;
struct state{
    int x , y;
    int steptype;
    int moves;
};
int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = {0 , -1 , 0 , 1};
int main(){
    int t; cin >> t;
    while(t--){
        int r, c;cin >> r >> c;
        vector<string>table(r);for(int a = 0 ; a < r ; a++) cin >> table[a];
        
        int sx , sy , ex , ey;
        for(int i = 0 ; i < r ; i++) for(int j = 0 ; j < c ; j++){
            if(table[i][j] == 'S'){sx = i , sy = j;}
            if(table[i][j] == 'E'){ex = i , ey = j;}
        }

        vector<vector<vector<bool>>> visited(r , vector<vector<bool>>(c , vector<bool>(3 , false)));
        queue<state> q;
        q.push({sx , sy , 0 , 0});
        visited[sx][sy][0] = true;
        int ans = -1;
        while (!q.empty())
        {
            state cur = q.front(); q.pop();
            int steplen = cur.steptype + 1;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.x , ny =cur.y;
                bool blocked = 0;
                for (int s = 0; s < steplen; s++){
                    nx += dx[dir];
                    ny += dy[dir];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || table[nx][ny] == '#'){
                        blocked = 1;
                        break;
                    }
                }
                if(blocked) continue;

                int nextstep = (cur.steptype + 1 ) % 3;
                if(visited[nx][ny][nextstep])continue;
                visited[nx][ny][nextstep] = true;

                if(nx == ex && ny == ey){
                    ans = cur.moves + 1;
                    goto finish;
                }
                q.push({nx , ny , nextstep , cur.moves + 1});
            }
        }
        finish:
        (ans == -1) ? cout <<"NO\n" : cout << ans << endl;
    }
    return 0;
}

