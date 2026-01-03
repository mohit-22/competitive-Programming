#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;

        vector<vector<int>>v(n,vector<int>(m));
        for(int i =0;  i<n ; i++){
            string s;
            cin >> s;
            for(int j=0;j<m;j++){
                v[i][j] = s[j] - '0';
            }
        }

        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int srow = 0,scol=0,erow=n-1,ecol=m-1;
        int ans=0;

        while(srow<=erow && scol<=ecol){
            vector<int>v1;
            for(int j=scol ; j<=ecol ; j++){
                v1.push_back(v[srow][j]);
            }

            for(int i=srow+1 ; i<=erow ; i++){
                v1.push_back(v[i][ecol]);
            }

            for(int j=ecol-1 ; j>=scol ; j--){
                if(srow==erow) break;
                v1.push_back(v[erow][j]);
            }

            for(int i=erow-1 ; i>=srow+1 ; i--){
                if(scol==ecol) break;
                v1.push_back(v[i][scol]);
            }

            srow++,scol++,erow--,ecol--;

            // for(int i=0 ; i<v1.size() ; i++){
            //     cout<<v1[i]<<" ";
            // }
            // cout<<endl;

            if(v1.size()>=4){
                int x = v1.size();
                for(int i=0 ; i+3<x ; i++){
                    if(v1[i]==1 && v1[i+1]==5 && v1[i+2]==4 && v1[i+3]==3){
                        ans++;
                    }
                }
                if(v1[x-3]==1 && v1[x-2]==5 && v1[x-1]==4 && v1[0]==3) ans++;
                if(v1[x-2]==1 && v1[x-1]==5 && v1[0]==4 && v1[1]==3) ans++;
                if(v1[x-1]==1 && v1[0]==5 && v1[1]==4 && v1[2]==3) ans++;

            }


        }

        cout<<ans<<endl;
        
    }
    return 0;
}