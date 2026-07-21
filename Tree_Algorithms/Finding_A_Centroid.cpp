// Problem : Finding a Centroid https://cses.fi/problemset/task/2079/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> subsz;

void dfs(int node, int parent){
    subsz[node] = 1;
    for(auto v : g[node]){
        if(v != parent){
            dfs(v, node);
            subsz[node] += subsz[v];
        }
    }
}
int centroid(int node, int parent){
    for(auto v : g[node]){
        if(v != parent && subsz[v] > n/2){
            return centroid(v, node);
        }
    }
    return node;
}
int main(){
    cin >> n;
    g.resize(n+1);
    subsz.resize(n+1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    cout << centroid(1, -1) << endl;
}