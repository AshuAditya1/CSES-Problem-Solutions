// Problem : Building Roads https://cses.fi/problemset/task/1666/
// Author : Ashu_Aditya
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;

void bfs(int sc_node){
    queue<int> q;
    vis[sc_node] = 1;
    q.push(sc_node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v : g[node]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
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
    int cc = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans.push_back(i);
            cc++;
            bfs(i);
        }
    }
    cout << cc - 1 << endl;
    for(int i = 0; i < cc - 1; i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }
}