// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// int ans=0;
// int solve(int i,vector<int>&v , int n , int k){
//     if(v.size()==k) return 1;
//     if(i==n+1) return 0; 
//     int ct=0;
//     for(int j=i ; j<=n ; j++){
//         if(j%v.back()==0){
//             v.push_back(j);
//             ct+=solve(j,v,n,k);
//             v.pop_back();
//         }
//     }
//     return ct;
// }

// int32_t main(){
    
//     int n,k;
//     cin>>n>>k;
    
//     vector<int>v;
//     for(int i=1 ; i<=n ; i++){
//         v.push_back(i);
//         ans+=solve(i,v,n,k);
//         v.pop_back();
//     }
//     cout<<ans<<endl;
        
    
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define int long long
int dp[2001][2001];
int ans=0;
int solve(int last,int len , int n , int k){
    if(len==k) return 1;
    if(last==n+1) return 0; 
    if(dp[last][len]!=-1) return dp[last][len]; 
    int ct=0;
    for(int j=last ; j<=n ; j+=last){
        if(j%last==0){
            // v.push_back(j);
            ct+=solve(j,len+1,n,k);
            if(ct>=MOD) ct = ct%MOD;
            // v.pop_back();
        }
    }
    return dp[last][len] =  ct%MOD;
}

int32_t main(){
    
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    // vector<int>v;
    for(int i=1 ; i<=n ; i++){
        // v.push_back(i);
        ans+=solve(i,1,n,k);
        // v.pop_back();
    }
    cout<<ans%MOD<<endl;
        
    
    return 0;
}