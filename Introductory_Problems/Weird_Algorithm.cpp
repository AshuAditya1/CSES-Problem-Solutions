// Problem : Weird Algorithm https://cses.fi/problemset/task/1068/
// Author : Ashu_Aditya
// Time Complexity : O(k), k : length of Collatz sequence
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    cout << 1 << endl;
}