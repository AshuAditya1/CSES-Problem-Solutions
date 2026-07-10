// Problem : Increasing Array https://cses.fi/problemset/task/1094/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i-1] > a[i]){
            ans += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << ans << endl;
}