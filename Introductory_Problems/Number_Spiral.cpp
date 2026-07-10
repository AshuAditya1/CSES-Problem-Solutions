// Problem : Number Spiral https://cses.fi/problemset/task/1071/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int r, c;
    cin >> r >> c;
    long long z = max(r,c);
    if(z % 2 == 0){
        if(z == r) cout << z * z - c + 1 << endl;
        else cout << (z - 1) * (z - 1) + r << endl;
    } else {
        if(z == c) cout << z * z - r + 1 << endl;
        else cout << (z - 1) * (z - 1) + c << endl;
    }
}
int main(){
    int tt; 
    cin >> tt;
    while(tt--){
        solve();
    }
}