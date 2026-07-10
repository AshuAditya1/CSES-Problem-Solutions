// Problem : Apple Division https://cses.fi/problemset/task/1623/
// Author : Ashu_Aditya
// Time Complexity : O(n*(2^n))
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll ans = LLONG_MAX;
    ll len = 1 << n;
    for(int i = 0; i < len; i++){
        ll sum1 = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sum1 += a[j];
            }
        }
        ll sum2 = sum - sum1;
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans << endl;
}