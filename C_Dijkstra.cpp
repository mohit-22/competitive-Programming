#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n,m;
    cin>>n>>m;
    using p = pair<int,int>;
    vector<vector<p>>adj(n+1);
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    vector<int>d(n+1,LLONG_MAX);
    vector<int>par(n+1);
    for(int i=0 ; i<n+1;i++){
        par[i] = i;
    }
    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,1});
    d[1] = 0;
    while(!pq.empty()){
        auto [dist,node] = pq.top();
        pq.pop();
        if(dist > d[node]) continue;
        for(auto it:adj[node]){
            auto [adjnode,adjdist] = it;
            if(dist+adjdist<d[adjnode]){
                par[adjnode] = node;
                d[adjnode] = dist+adjdist;
                pq.push({dist+adjdist,adjnode});
            }
        }
    }
    // for(auto it:d){
    //     cout<<it<<" ";
    // }
    if(d[n]==LLONG_MAX){
        cout<<-1<<endl;
        return 0;
    }
    vector<int>v;
    int i=n;
    while(par[i]!=i){
        v.push_back(i);
        i = par[i];
    }
    v.push_back(1);
    reverse(v.begin(),v.end());
    for(auto it:v){
        cout<<it<<" ";
    }

    return 0;
}