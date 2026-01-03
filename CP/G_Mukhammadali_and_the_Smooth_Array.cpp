#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int tt=0;
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
            tt+=brr[i];
        }

        vector<int>dp(n,0);
        int ans=0;
        for(int i=0 ; i<n ; i++){
            dp[i] = brr[i];
            for(int j=i-1 ; j>=0 ; j--){
                if(arr[j]<=arr[i]){
                    dp[i] = max(dp[i],dp[j]+brr[i]);
                }
            }
            ans = max(ans,dp[i]);
        }
        cout<<tt-ans<<endl;
    }
    return 0;
}