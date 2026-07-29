// Problem : Tree Distances II https://cses.fi/problemset/task/1133/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<vector<int>> g;
vector<int> dis, subsz;
vector<ll> ans;

void dfs(int node, int parent, int d){
    subsz[node] = 1;
    dis[node] = d;
    for(auto v : g[node]){
        if(v != parent){
            dfs(v, node, d + 1);
            subsz[node] += subsz[v];
        }
    }
}
void dfs_reroot(int node, int parent, ll sum){
    ans[node] = sum;
    for(auto v : g[node]){
        if(v != parent){
            dfs_reroot(v, node, sum - subsz[v] + (n - subsz[v]));
        }
    }
}
int main(){
    cin >> n;
    g.resize(n+1);
    dis.resize(n+1);
    subsz.resize(n+1);
    ans.resize(n+1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1, 0);
    ll sum = 0;
    for(int x = 1; x <= n; x++) sum += dis[x];
    dfs_reroot(1,-1,sum);
    for(int x = 1; x <= n; x++) cout << ans[x] << " ";
}