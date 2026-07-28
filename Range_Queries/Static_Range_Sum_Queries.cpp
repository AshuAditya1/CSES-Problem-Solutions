// Problem : Static Range Sum Queries https://cses.fi/problemset/task/1646/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(n)
 
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    } 
    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a == 0) cout << prefix_sum[b] << endl;
        else cout << prefix_sum[b] - prefix_sum[a-1] << endl;
    }
}