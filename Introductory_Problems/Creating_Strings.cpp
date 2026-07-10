// Problem : Creating Strings https://cses.fi/problemset/task/1622/
// Author : Ashu_Aditya
// Time Complexity : O(n*logn + k*n)
// Space Complexity : O(k*n)

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do{
        ans.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << ans.size() << endl;
    for(auto it : ans) cout << it << endl;
}