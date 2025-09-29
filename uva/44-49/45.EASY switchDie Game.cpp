#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T; 
    while(cin >> T , T){
        int top = 1 , north = 2 , west = 3 , south = 5 , east = 4 , bottom = 6;

        while (T--)
        {
            string cmd;
            int cases = 0;
            cin >> cmd;
            if(cmd == "north") cases = 1;
            else if(cmd == "east") cases = 2;
            else if(cmd == "south") cases = 3;
            else if(cmd == "west") cases = 4;

            switch (cases)
            {
            case 1 : tie(top , north , bottom ,south) = make_tuple(south , top , north , bottom);
                break;
            case 2 : tie(top , east , bottom , west) = make_tuple(west , top , east , bottom);
                break;
            case 3 : tie(top , south , bottom , north) = make_tuple(north , top , south , bottom);
                break;
            case 4 : tie(top , west , bottom ,east) = make_tuple(east , top , west , bottom);
                break;
            }
            
        }
        cout << top << endl;
    }
    return 0;
}