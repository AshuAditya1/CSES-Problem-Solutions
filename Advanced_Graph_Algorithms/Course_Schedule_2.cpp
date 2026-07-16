// Problem : Course Schedule II https://cses.fi/problemset/task/1757/
// Author : Ashu_Aditya
// Time Complexity : O(m + n log(n))
// Space Complexity : O(n + m)


#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;

void kahn_algo(){
    priority_queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int curr = q.top();
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
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[v].push_back(u);
        indeg[u]++;
    }
    kahn_algo();
    if(topo.size() != n){
        cout << "IMPOSSIBLE\n";
    } else {
        reverse(topo.begin(), topo.end());
        for(auto it : topo) cout << it << " ";
        cout << endl;
    }
}