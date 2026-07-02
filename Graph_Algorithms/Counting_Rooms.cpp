// Author : Ashu_Aditya
// Time Complexity : O(n * m)
// Space Complexity : O(n * m)

#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
using state = pair<int, int>;
 
int n, m;
vector<string> a;
vector<vector<int>> vis;
queue<state> q;
 
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
    q.push(st);
    while(!q.empty()){
        state node = q.front();
        q.pop();
        if(vis[node.ff][node.ss]) continue;
        vis[node.ff][node.ss] = 1;
        for(auto v : neighbours(node)){
            if(!vis[v.ff][v.ss]){
                q.push(v);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vis.assign(n, vector<int>(m,0));
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.' && !vis[i][j]){
                c++;
                state st = {i, j};
                bfs(st);
            }
        }
    }
    cout << c << endl;
}