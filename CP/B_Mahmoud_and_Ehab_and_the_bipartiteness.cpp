#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        vector<int>adj(n+1,0);
        int x = n-1;
        while(x--){
            int u,v;
            cin>>u>>v;
            adj[u]++; 
        }
        int ans=0;
        for(int i=1 ; i<=n ; i++){
            if(adj[i]!=-1) ans+=(n-adj[i]-1);
        }
        cout<<ans<<endl;
        
    // }
    return 0;
}

