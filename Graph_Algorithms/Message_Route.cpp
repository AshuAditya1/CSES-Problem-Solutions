// Problem : Message Route https://cses.fi/problemset/task/1667
// Author : Ashu_Aditya
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)


#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> dist;
vector<int> par;

void bfs(int sc_node){
    queue<int> q;
    vis[sc_node] = 1;
    dist[sc_node] = 0;
    q.push(sc_node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v : g[node]){
            if(!vis[v]){
                vis[v] = 1;
                dist[v] = dist[node] + 1;
                par[v] = node;
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
    dist.assign(n+1, INT_MAX);
    par.assign(n+1, -1);
    
    bfs(1);
    if(dist[n] == INT_MAX){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dist[n] + 1 << endl;
    vector<int> path;
    int curr = n;
    while(curr != -1){
        path.push_back(curr);
        curr = par[curr];
    }
    reverse(path.begin(), path.end());
    for(auto it : path) cout << it << " ";
}
