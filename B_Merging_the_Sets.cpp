#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        map<int,vector<int>>mp;
        for(int i=1 ; i<=n ; i++){
            int l;cin>>l;
            for(int j=1 ; j<=l ; j++){
                int x;cin>>x;
                mp[x].push_back(i);
            }
        }
        if(mp.size()<m){
            cout<<"NO"<<endl;
            continue;
        }
        // int ct=0;
        set<int>s;
        for(auto it:mp){
            if((it.second).size()==1){
                s.insert(it.second[0]);
            }
        }
        // cout<<ct<<endl;
        int x=n-s.size();
        if(x<2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

        
        
    }
    return 0;
}