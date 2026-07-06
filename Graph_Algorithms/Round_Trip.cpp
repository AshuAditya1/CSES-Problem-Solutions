// Problem : Round Trip https://cses.fi/problemset/task/1669/
// Author : Ashu_Aditya
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
vector<int> ans;

bool f = false;

void dfs(int node, int par){
    vis[node] = 1;
    parent[node] = par;
    for(auto v : g[node]){
        if(f) return;
        if(v == parent[node]) continue;
        if(!vis[v]){
            dfs(v, node);
        } else {
            int temp = node;
            ans.push_back(v);
            while(temp != v){
                ans.push_back(temp);
                temp = parent[temp];
            }
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            f = true;
            return;
        }
    }
}
int main(){
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    if(f){
        cout << ans.size() << endl;
        for(auto it : ans) cout << it << " ";
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}