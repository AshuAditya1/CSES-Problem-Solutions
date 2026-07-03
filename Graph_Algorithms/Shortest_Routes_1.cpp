// Problem : Shortest Routes I https://cses.fi/problemset/task/1671/
// Author : Ashu_Aditya
// Time Complexity : O((n + m) log n)
// Space Complexity : O(n + m)

#include<bits/stdc++.h>
using namespace std;

#define ff first 
#define ss second
#define ll long long

int n, m;
vector<vector<pair<int, ll>>> g;
vector<int> vis;
vector<ll> dis;

void dijkstra(int sc_node){
    vis.assign(n + 1 ,0);
    dis.assign(n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>> pq;
    dis[sc_node] = 0;
    pq.push({-0, sc_node});
    while(!pq.empty()){
        int curr = pq.top().ss;
        pq.pop();
        if(vis[curr]) continue;
        vis[curr] = 1;
        for(auto v : g[curr]){
            if(!vis[v.ff] && dis[v.ff] > dis[curr] + v.ss){
                dis[v.ff] = dis[curr] + v.ss;
                pq.push({-dis[v.ff], v.ff});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w; 
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
}