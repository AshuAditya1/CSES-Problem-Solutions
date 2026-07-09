// Problem : Trailing Zeros https://cses.fi/problemset/task/1618/
// Author : Ashu_Aditya
// Time Complexity : O(log5(n))
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int cnt = 0;
    for(int i = 0; i <= n; i += 5){
        if(i == 0) continue;
        int dup = i;
        while(dup % 5 == 0){
            cnt++;
            dup /= 5;
        }
    }
    cout << cnt << endl;
}