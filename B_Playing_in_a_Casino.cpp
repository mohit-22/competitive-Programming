#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        vector<vector<int>>v(m,vector<int>(n)); // rotated matrix
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin>>v[j][i];
            }
        }

        for(int i=0 ; i<m ; i++){
            sort(v[i].begin(),v[i].end());
        }

        int ans=0;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                ans+= (1)*v[i][j]*(j);
                ans+= (-1)*v[i][j]*(n-j-1);
            }
        }
        cout<<ans<<endl;


        
    }
    return 0;
}