#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n>>q;
        vector<int>v(n+1,0);
        while(q--){
            int a,b;
            cin>>a>>b;
            if(a>b) swap(a,b);
            v[b] = max(v[b],a);
        }
        for(int i=1 ; i<n+1 ; i++){
            v[i] = max(v[i],v[i-1]);
        }
        int ct=0;
        for(int i=1 ; i<n+1 ; i++){
            auto it = lower_bound(v.begin()+i,v.end(),i);
            int idx = it-v.begin();
            idx--;
            // ct+=(idx-i+1);
            if(idx >= i){
                ct += (idx - i + 1);
            }
        }
        cout<<ct<<endl;
        
    }
    return 0;
}