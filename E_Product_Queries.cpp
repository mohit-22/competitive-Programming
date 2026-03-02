#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>dp(n+1,INT_MAX);
        for(int i=0 ;i<n ; i++){
            int x;
            cin>>x;
            dp[x]=1;
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j*j<=i ; j++){
                if(i%j==0) dp[i] = min(dp[i],dp[j]+dp[i/j]);
            }
        }
        for(int i=1 ; i<=n ; i++){
            cout<< ((dp[i]==INT_MAX) ? -1 : dp[i])<<" "; 
        }
        cout<<endl;
    }
    return 0;
}