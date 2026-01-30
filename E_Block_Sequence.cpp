#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> dp(n+3,0);
        for(int i=n;i>=1;--i){
            int end = i + a[i];
            if(end <= n) dp[i] = max(dp[i+1], a[i] + 1 + dp[end+1]);
            else dp[i] = dp[i+1];
        }
        cout << (n - dp[1]) << '\n';
    }
    return 0;
}