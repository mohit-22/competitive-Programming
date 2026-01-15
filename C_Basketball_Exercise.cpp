#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>dp;
int N;
int solve(int i,int j,vector<vector<int>>&v){
    if(j>=N) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int take = solve(i,j+1,v);
    int nontake = v[i][j] + solve(1-i,j+1,v);

    return dp[i][j] =  max(take,nontake);
}


int32_t main(){

        int n;
        cin >> n;
        N=n;
        vector<vector<int>>v(2,vector<int>(n));
        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<n ; j++){
                cin>>v[i][j];
            }
        }
        
        dp.assign(2,vector<int>(n+1,-1));
        int a  = solve(0,0,v);
        int b = solve(1,0,v);

        cout<<max(a,b);
         
   

    return 0;
}