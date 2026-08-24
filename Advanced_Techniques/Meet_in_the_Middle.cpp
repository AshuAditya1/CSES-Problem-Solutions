// Problem : Meet in the Middle https://cses.fi/problemset/task/1628/
// Author : Ashu_Aditya
// Time Complexity : O(n * 2^(n/2))
// Space Complexity : O(2^(n/2))

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> s1, s2;
    for(int i = 0; i < n/2; i++) s1.push_back(a[i]);
    for(int i = n/2; i < n; i++) s2.push_back(a[i]);
    vector<ll> sum1, sum2;
    for(int mask = 0; mask < (1LL << s1.size()); mask++){
        ll sum = 0;
        for(int i = 0; i < s1.size(); i++){
            if((mask & (1 << i)) != 0){
                sum += s1[i];
            }
        }
        sum1.push_back(sum);
    }
    for(int mask = 0; mask < (1LL << s2.size()); mask++){
        ll sum = 0;
        for(int i = 0; i < s2.size(); i++){
            if((mask & (1 << i)) != 0){
                sum += s2[i];
            }
        }
        sum2.push_back(sum);
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    ll ans = 0;
    for(auto it : sum1){
        auto l = lower_bound(sum2.begin(), sum2.end(), x - it);
		auto r = upper_bound(sum2.begin(), sum2.end(), x - it);
		ans += r - l;
    }
    cout << ans << endl;
}
int main() {
	solve();
}