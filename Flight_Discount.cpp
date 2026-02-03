#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n,m;
    cin>>n>>m;
    using p = pair<int,pair<int,int>>;
    vector<vector<pair<int,int>>>adj(n+1);
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
    }
    vector<vector<int>>d(n+1,vector<int>(2,LLONG_MAX));
    priority_queue<p,vector<p>,greater<p>>pq;
    d[1][0] = 0;
    d[1][1] = 0;
    pq.push({0,{1,0}});

    while(!pq.empty()){
        auto [dist,x] = pq.top();
        pq.pop();
        auto [node,chk] = x;

        if(dist > d[node][chk]) continue;

        for(auto it:adj[node]){
            auto [adjnode,adjdist] = it;


            if(chk==0){
                if(dist+(adjdist)/2 < d[adjnode][1]){
                    d[adjnode][1] = dist+(adjdist)/2;
                    pq.push({dist+(adjdist)/2,{adjnode,1}});
                }
                if(dist+(adjdist) < d[adjnode][0]){
                    d[adjnode][0] =  dist+(adjdist);
                    pq.push({dist+(adjdist),{adjnode,0}});
                }
            }
            else{
                if(dist+(adjdist) < d[adjnode][1]){
                    d[adjnode][1] =  dist+(adjdist);
                    pq.push({dist+(adjdist),{adjnode,1}});
                }
            }

        }
    }
    cout<<d[n][1]<<endl;

    return 0;
}