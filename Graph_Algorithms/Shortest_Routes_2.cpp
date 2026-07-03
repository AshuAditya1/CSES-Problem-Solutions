// Problem : Shortest Routes II https://cses.fi/problemset/task/1672/
// Author : Ashu_Aditya
// Time Complexity : O(n^3 + q)
// Space Complexity : O(n^2)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 4e18;

int n, m, q;
vector<vector<ll>> dis;

void floyd_warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] == INF || dis[k][j] == INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    dis.assign(n + 1, vector<ll>(n + 1, INF));
    for(int i = 0; i <= n; i++) dis[i][i] = 0;
    for(int i = 0; i < m; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    floyd_warshall();
    while(q--){
        int a, b; cin >> a >> b;
        if(dis[a][b] == INF) cout << -1 << endl;
        else cout << dis[a][b] << endl;
    }
}