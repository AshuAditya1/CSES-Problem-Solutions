// Problem : Palindrome Reorder https://cses.fi/problemset/task/1755/
// Author : Ashu_Aditya
// Time Complexity : O(n*log(n))
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    string s; cin >> s;
    map<char, ll> mpp;
    for(auto it : s) mpp[it]++;

    ll oddcnt = 0;
    for(auto it : mpp){
        if(it.second % 2 != 0) oddcnt++;
        if(oddcnt > 1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    string ans = "", s1 = "", s2 = "", s3 = "";
    for(auto it : mpp){
        if(it.second % 2 == 0){
            for(int i = 0; i < it.second/2; i++){
                s1 += it.first;
                s2 += it.first;
            }
        } else {
            for(int i = 0; i < it.second; i++){
                s3 += it.first;
            }
        }
    }
    sort(s2.begin(),s2.end(),greater<int>());
    ans += s1; ans += s3; ans += s2;
    cout << ans << endl;
}