// Problem : Creating Strings II https://cses.fi/problemset/task/1715/
// Author : Ashu_Aditya
// Time Complexity : O(n + log(MOD))
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define ll long long 

ll mybinPow(ll a, ll b){ 
    ll res = 1;  
    while (b > 0){ 
        if (b & 1) res = res * a % MOD; 
        a = a * a % MOD;
        b = b >> 1; 
    } 
    return res; 
}
ll inverse(ll a){ 
    return mybinPow(a, MOD - 2); 
}
ll fact[1000001]; 
ll invfact[1000001];
void precompute_fact(){
	fact[0] = 1;
	for(ll i = 1; i <= 1000000; i++){ 
        fact[i] = (fact[i-1] * i) % MOD; 
    }
	invfact[1000000] = inverse(fact[1000000]);
	for(ll i = 1000000; i >= 1; i--){ 
        invfact[i-1] = (invfact[i] * i) % MOD; 
    }
}
int main(){
    precompute_fact();
    string s; cin >> s;
    ll n = s.size();
    map<char, ll> mpp;
    for(auto it : s) mpp[it]++;
    ll ans = fact[n] % MOD;
    for(auto it : mpp){
        ans = (ans * invfact[it.second]) % MOD;
    }
    cout << ans << endl;
}