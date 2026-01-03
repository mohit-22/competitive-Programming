#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;

int nCr(int n, int r,vector<int>&dp2) {
    if (r>n) return 0;
    if(dp2[n]!=-1) return dp2[n];
    vector<int> dp(r + 1, 0);
    dp[0] =1; 
    for (int i=1;i<=n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % M;
        }
    }
    dp[n] = dp[r]; 
    return dp[r];
}


int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n,r;
        cin >>n>>r;
        int sum = 0;
        vector<int>dp(n+2,-1);
        for (int i=1;i<=n+1-r;i++) {
            int x = (n+1)-i;
            int y = nCr(x,r,dp);
            sum+=(y%M);
        }
        cout << sum << endl;
    }
    return 0;
}
