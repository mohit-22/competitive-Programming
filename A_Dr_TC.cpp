#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;
        int ct1=0;
        int ct0=0;
        for(int i=0  ;i<n ; i++){
            if(s[i]=='0') ct0++;
            else ct1++;
        }
         cout<<ct1*(ct1-1) + (ct1+1)*ct0<<endl;

    }
    return 0;
}