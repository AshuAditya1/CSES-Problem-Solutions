// Problem : Building Teams https://cses.fi/problemset/task/1668/
// Author : Ashu_Aditya
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> color;

bool is_bipatite = true;

void dfs(int node, int col){
    vis[node] = 1;
    color[node] = col;
    for(auto v : g[node]){
        if(!vis[v]){
            dfs(v, 3 - col);
        } else if(color[v] == color[node]){
            is_bipatite = false;
            return;
        }
    }
}
int main(){
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n+1, 0);
    color.assign(n+1, 0);
    for(int x = 1; x <= n; x++){
        if(!vis[x]){
            dfs(x, 1);
        }
    }
    if(is_bipatite){
        for(int i = 1; i <= n; i++){
            cout << color[i] << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}