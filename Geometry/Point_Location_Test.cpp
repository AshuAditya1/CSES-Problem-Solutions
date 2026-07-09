// Problem : Point Location Test https://cses.fi/problemset/task/2189/
// Author : Ashu_Aditya
// Time Complexity : O(T), O(1) per testcase
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

void solve(){
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    ll val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if(val > 0) cout << "LEFT" << endl;
    if(val < 0) cout << "RIGHT" << endl;
    if(val == 0) cout << "TOUCH" << endl;
}

int main(){
    ll tt; 
    cin >> tt;
    while(tt--){
        solve();
    }
}