// Problem : Two Knights https://cses.fi/problemset/task/1072/
// Author : Ashu_Aditya
// Time Complexity : O(n)
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
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int k = i;
        ll place = (power(k, 2) * (power(k, 2) - 1)) / 2;
        ll attack = 4 * (k - 1) * (k - 2);
        ll ans = place - attack;
        cout << ans << endl;
    }
}