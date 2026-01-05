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
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int sz = (n+1)/2;
        vector<vector<int>>dp(sz,vector<int>(2,0));
        
        for(int i=1 ; i<sz ; i++){
            dp[i][0] = min((dp[i-1][0] + (arr[i]==arr[i-1]) + (arr[n-i-1]==arr[n-i])) , (dp[i-1][1]+(arr[i]==arr[n-i]) + (arr[n-i-1]==arr[i-1])) );

            dp[i][1] = min(dp[i-1][0] + (arr[n-i-1]==arr[i-1]) + (arr[i]==arr[n-i]) , dp[i-1][1]+(arr[n-i-1]==arr[n-i])+(arr[i]==arr[i-1]));
        }

        int mn = min(dp[sz-1][0] , dp[sz-1][1]);
        if(n%2==0){
            mn+= (arr[sz-1]==arr[sz]);
        }

        cout<<mn<<endl;

    }
    return 0;
}   