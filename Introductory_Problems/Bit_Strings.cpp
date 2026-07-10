// Problem : Bit Strings https://cses.fi/problemset/task/1617/
// Author : Ashu_Aditya
// Time Complexity : O(1)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const ll MOD = 1e9 + 7;

ll power(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int main(){
    ll n; cin >> n;
    cout << power(2, n) % MOD << endl;
}