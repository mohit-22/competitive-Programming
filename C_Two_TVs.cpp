#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin>>n;
    vector<pair<int,int>>vp ;
    while(n--){
        int l,r;
        cin>>l>>r;
        vp.push_back({l,1});
        vp.push_back({r,-1});
    }
    sort(vp.begin(),vp.end() , [](auto &a,auto &b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second>b.second;
    });
    int curr=0;
    for(auto it:vp){
        curr+=it.second;
        if(curr>2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}