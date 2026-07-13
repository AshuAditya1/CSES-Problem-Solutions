// Problem : Tree Diameter https://cses.fi/problemset/task/1131/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> dis;

void dfs(int node, int par, int d){
    dis[node] = d;
    for(auto v : g[node]){
        if(v != par){
            dfs(v, node, d + 1);
        }
    }
}
int main(){
    cin >> n;
    g.resize(n+1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis.resize(n+1);
    dfs(1,0,0);
    int x = 1;
    for(int i = 1; i <= n; i++){
        if(dis[i] > dis[x]) x = i;
    }
    dfs(x,0,0);
    int y = 1;
    for(int i = 1; i <= n; i++){
        if(dis[i] > dis[y]) y = i;
    }
    cout << dis[y] << endl;
}