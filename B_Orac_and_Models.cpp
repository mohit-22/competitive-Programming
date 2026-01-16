// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// int N;
// vector<vector<int>>dp;
// int solve(int prev,int i,int arr[]){
//     if(i>N) return 0;
//     if(dp[prev][i]!=-1) return dp[prev][i];
//     int take = 0;
//     if(prev==0 || (i%prev==0 && arr[i-1]>arr[prev-1])){
//         take = 1+solve(i,i+i,arr);
//     }
//     int nontake = solve(prev,i+1,arr);
//     return dp[prev][i] =  max(take,nontake);
// }

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin>>n;
//         N=n;
//         int arr[n];
//         dp.assign(n+1,vector<int>(n+1,-1));
//         for(int i=0 ; i<n  ;i++){
//             cin>>arr[i];
//         }
//         cout<<solve(0,1,arr)<<endl;
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define int long long
int N;
vector<int>dp;
int solve(int i,int arr[]){
    if(i>N) return 0;
    if(dp[i]!=-1) return dp[i];
    int take = 0;
    
    for(int j=i*2 ; j<=N ; j+=i){
        if(arr[j-1]>arr[i-1]) {
            take = max(take, 1 + solve(j,arr));
        }
    }
    return dp[i] =  take;  
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        N=n;
        int arr[n];
        dp.assign(n+1,-1);
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
        }
        int ans = 0;
        for(int i=1  ;i<=n ; i++){
            ans = max(ans,1+solve(i,arr));
        }
        cout<<ans<<endl;
    }
    return 0;
}