// Problem : Course Schedule https://cses.fi/problemset/task/1679/
// Author : Ashu_Aditya
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;

void kahn_algo(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for(auto v : g[curr]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
}

int main(){
    cin >> n >> m;
    g.resize(n+1);
    indeg.assign(n+1, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    kahn_algo();
    if(topo.size() != n){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(auto v : topo) cout << v << " ";
    }
}