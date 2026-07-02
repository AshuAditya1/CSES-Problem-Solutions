// Problem : Labyrinth https://cses.fi/problemset/task/1193
// Author : Ashu_Aditya
// Time Complexity : O(n * m)
// Space Complexity : O(n * m)

#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define INF 1e9
using state = pair<int, int>;
 
int n, m;
vector<string> a;
vector<vector<int>> vis, dis;
queue<state> q;
vector<vector<state>> par;
 
bool valid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#') return true;
    return false;
}
 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
 
vector<state> neighbours(state curr){
    vector<state> neigh;
    for(int dir = 0; dir < 4; dir++){
        int x = curr.ff + dx[dir];
        int y = curr.ss + dy[dir];
        if(valid(x, y)){
            neigh.push_back({x, y});
        }
    }
    return neigh;
}
 
void bfs(state st){
    vis.assign(n, vector<int>(m,0));
    dis.assign(n, vector<int>(m,INF));
    par.assign(n, vector<state>(m, {-1, -1}));
    
    dis[st.ff][st.ss] = 0;
    q.push(st);
    
    while(!q.empty()){
        state node = q.front();
        q.pop();
        if(vis[node.ff][node.ss]) continue;
        vis[node.ff][node.ss] = 1;
        
        for(auto v : neighbours(node)){
            if(!vis[v.ff][v.ss] and dis[v.ff][v.ss] > dis[node.ff][node.ss] + 1){
                dis[v.ff][v.ss] = dis[node.ff][node.ss] + 1;
                par[v.ff][v.ss] = node;
                q.push(v);
            }
        }
    }
}
void print(state st, state en){
    state curr = en;
    vector<state> path;
    while(curr != make_pair(-1,-1)){
        path.push_back(curr);
        curr = par[curr.ff][curr.ss];
    }
    reverse(path.begin(), path.end());
    int x = path.size();
    vector<char> ans;
    for(int i = 0; i < x - 1; i++){
        int curr_x = path[i].ff;
        int curr_y = path[i].ss;
        int nxt_x = path[i+1].ff;
        int nxt_y = path[i+1].ss;
        if(nxt_x - curr_x == 1) ans.push_back('D');
        else if(curr_x - nxt_x == 1) ans.push_back('U');
        else if(nxt_y - curr_y == 1) ans.push_back('R');
        else if(curr_y - nxt_y == 1) ans.push_back('L');
    }
    for(auto it : ans) cout << it;
}
int main(){
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    state st, en;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'A') st = {i, j};
            else if(a[i][j] == 'B') en = {i, j};
        }
    }
    bfs(st);
    if(vis[en.ff][en.ss]){
        cout << "YES" << endl;
        cout << dis[en.ff][en.ss] << endl;
        print(st, en);
    } else {
        cout << "NO" << endl;
    }
}