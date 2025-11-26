#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int>parent;
    DSU(int n){parent.assign(n , -1);}

    int find(int x){return parent[x] < 0 ? x : parent[x] = find(parent[x]);}

    void unite(int a , int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(parent[a] > parent[b]) swap(a , b);
        parent[a] += parent[b];
        parent[b] = a;
    }

    int count() {
        int cnt = 0;
        for (int i = 0; i < (int) parent.size() ; i++) if(parent[i] < 0) cnt++;
        return cnt; 
    }
};

int main(){
    int T; cin >> T;cin.ignore();cin.ignore();
    while(T--){
        char maxNode; cin >> maxNode;cin.ignore();

        int n = maxNode - 'A' + 1;
        DSU dsu(n);

        string line;
        while(getline(cin , line)){
            if(line.empty()) break;
            int u = line[0] -'A';
            int v = line[1] -'A';
            dsu.unite(u , v);
        }

        cout << dsu.count() << "\n";
        if(T) cout << "\n";
    }

    return 0;
}