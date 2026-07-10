// Problem : Coin Piles https://cses.fi/problemset/task/1754/
// Author : Ashu_Aditya
// Time Complexity : O(T), O(1) per testcase
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b; cin >> a >> b;
    if((2 * a - b) % 3 == 0 and (2 * b - a) % 3 == 0 and min(a, b) * 2 >=  max(a, b)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}