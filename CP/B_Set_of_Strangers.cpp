#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        unordered_map<int,int>mp;
        set<int>s1;
        vector<vector<int>>v(n,vector<int>(m));
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int x;
                cin>>x;
                v[i][j] = x;
                s1.insert(x);
                mp[x]++;
            }
        }
        set<int>s;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int x = v[i][j];
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir];   // new row
                    int nj = j + dy[dir];   // new col

                    // check bounds
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        // (ni, nj) is a valid adjacent cell
                        int val = v[ni][nj];
                        if(val==x) s.insert(x);
                        // yahan tum kuch bhi kaam kar sakte ho
                    }
                }
            }
        }
        int ans = 2*s1.size();
        for(auto it:s1){
            if(s.find(it)==s.end()){
                ans-=1;
            }
        }

        // if(s.size()>0){
        //     ans-=2;
        // }
        // else 
        int mx = 0;
        for(auto it:s){
            mx = max(mp[it],mx);
        }
        if(mx!=0) ans-=2;
        if(mx==0){
            ans-=1;
        }
        cout<<ans<<endl;


        
        
    }
    return 0;
}