#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n>>s;
        int ct=0;
       while(n--){
        int dx,dy,x,y;
        cin>>dx>>dy>>x>>y;

        if(x==y && dx==dy){
            ct++;
        }
        if(x+y==s && dx==-dy){
            ct++;
        }
       }
       cout<<ct<<endl;
        
        
    }
    return 0;
}