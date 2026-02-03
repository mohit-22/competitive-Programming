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
        // adj[b].push_back({a,d});
    }
    vector<int>d(n+1,LLONG_MAX);
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
                d[adjnode] = dist+adjdist;
                pq.push({dist+adjdist,adjnode});
            }
        }
    }
    for(int i=1 ; i<n+1 ; i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    return 0;
}