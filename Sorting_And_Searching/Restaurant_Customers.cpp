// Problem : Restaurant Customers https://cses.fi/problemset/task/1619/
// Author : Ashu_Aditya
// Time Complexity : O(n*logn)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> times;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        times.push_back(a[i].first);
        times.push_back(a[i].second);
    }
    sort(times.begin(), times.end());
    int sz = times.size();
    vector<int> cnt(sz, 0);
    for(int i = 0; i < n; i++){
        int arr = a[i].first, dept = a[i].second;
        int arrIndex = lower_bound(times.begin(), times.end(), arr) - times.begin();
        int deptIndex = lower_bound(times.begin(), times.end(), dept) - times.begin();
        cnt[arrIndex]++;
        cnt[deptIndex]--;
    }
    vector<int> prefix(sz + 1);
    prefix[0] = cnt[0];
    for(int i = 1; i < sz; i++){
        prefix[i] = prefix[i-1] + cnt[i];
    }
    int ans = 0;
    for(int i = 0; i < sz; i++){
        ans = max(ans, prefix[i]);
    }
    cout << ans << endl;
}