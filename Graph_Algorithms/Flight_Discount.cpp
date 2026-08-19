// Problem : Flight Discount https://cses.fi/problemset/task/1195/
// Author : Ashu_Aditya
// Time Complexity : O((n+m)*log n)
// Space Complexity : O(n+m)

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first 
#define ss second 

const ll INF = 4e18;

ll n, m;
vector<tuple<ll, ll, ll>> edges;
vector<vector<pair<ll, ll>>> g1, g2;
vector<ll> vis, dis;

void dijkstra(ll sc_node, vector<vector<pair<ll, ll>>> &g){
    vis.assign(n+1, 0);
    dis.assign(n+1, INF);
    priority_queue<pair<ll,ll>> pq;
    dis[sc_node] = 0;
    pq.push({-0, sc_node});
    while(!pq.empty()){
        auto curr = pq.top().ss;
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
    g1.resize(n+1);
    g2.resize(n+1);
    for(int i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
        g1[u].push_back({v, w});
        g2[v].push_back({u, w});
    }
    dijkstra(1, g1);
    auto dis1 = dis;
    dijkstra(n, g2);
    auto dis2 = dis;
    ll ans = INF;
    for(auto it : edges){
        ll u = get<0>(it);
        ll v = get<1>(it);
        ll w = get<2>(it);
        if(dis1[u] == INF or dis2[v] == INF) continue;
        ll distance = dis1[u] + dis2[v] + (w/2);
        ans = min(ans, distance);
    }
    cout << ans << endl;
}