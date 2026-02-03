#include <bits/stdc++.h>
using namespace std;

#define int long long

int M = 1e9+7;

int32_t main(){
    int n,m;
    cin>>n>>m;
    using p = pair<int,int>;
    vector<vector<p>>adj(n+1);
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
    }
    vector<int>d(n+1,LLONG_MAX);
    vector<int>ways(n+1,0);
    vector<int>minpath(n+1,LLONG_MAX);
    vector<int>mxpath(n+1,LLONG_MIN);
    mxpath[1] = 0;
    minpath[1] = 0;
    ways[1] = 1;
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
                ways[adjnode] = ways[node];
                minpath[adjnode] = minpath[node]+1;
                mxpath[adjnode] = mxpath[node]+1;
            }
            else if(dist+adjdist==d[adjnode]){
                ways[adjnode] = (ways[adjnode]+ways[node])%M;
                minpath[adjnode] = min(minpath[adjnode],minpath[node]+1);
                mxpath[adjnode] = max(mxpath[adjnode],mxpath[node]+1);
            }
        }
    }

    cout<<d[n]<<" ";
    cout<<(ways[n])<<" ";
    cout<<minpath[n]<<" ";
    cout<<mxpath[n]<<" ";
   

    return 0;
}