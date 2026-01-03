#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int x=1;
        int ct=0;
        // int n = 9;
        int p = 1;
        while(p <= n){
            p <<= 1; // multiply by 2
        }
        // cout << p;
        while(x<p && x<=m){
            int a = n^x;
            if(a!=0){
                if(n%a==0 || x%a==0) ct++;
                // x++;
            }
            x++;
        }
        cout<<ct<<endl;
        
    }
    return 0;
}