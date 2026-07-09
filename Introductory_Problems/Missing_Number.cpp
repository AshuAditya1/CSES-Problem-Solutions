// Problem : Missing Number https://cses.fi/problemset/task/1083/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ll n; 
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll total = n * (n + 1) / 2;
    cout << total - sum << endl;
}