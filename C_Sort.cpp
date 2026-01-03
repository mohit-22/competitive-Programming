#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n>>q;
        string a,b;
        cin>>a>>b;
        for(int it=0 ; it<q ; it++){
            int x,y;
            cin>>x>>y;
            unordered_map<int,int>mpa,mpb;
            for(int i=x-1 ; i<y ; i++){
                mpa[a[i]]++;
            }
            for(int i=x-1 ; i<y ; i++){
                mpb[b[i]]++;
            }
            int ct=0;
            // int ct = llabs(mpb.size()-mpa.size());
            for(auto itt:mpa){
                if(mpb.find(itt.first)==mpb.end()) ct++;
            }
            cout<<ct<<endl;
                
        }
        
    }
    return 0;
}