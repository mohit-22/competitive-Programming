#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int r,x,d,n;
        cin >> r>>x>>d>>n;
        string arr;
        cin>>arr;
        int ct=0;
        for(int i=0 ; i<n ; i++){
            if(arr[i]=='2'){
                if(r<x) ct++;
            }
            else{
                ct++;
                r=max(0LL,r-d);
            }
        }
        cout<<ct<<endl;
        
    }
    return 0;
}