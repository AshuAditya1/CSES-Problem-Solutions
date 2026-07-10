// Problem : Repititions https://cses.fi/problemset/task/1069/
// Author : Ashu_Aditya
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int l = 0, r = 0;
    int ans = 0;
    int curr = 0;
    while(r < n){
        if(s[l] == s[r]){
            r++;
            curr++;
        } else {
            ans = max(ans,curr);
            l = r;
            curr = 0;
        }
    }
    ans = max(ans, curr);
    cout << ans << endl;
}