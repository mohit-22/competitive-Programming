#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    vector<int> qs(t);
    int maxN = 0;
    for(int i=0;i<t;i++){
        cin>>qs[i];
        if(qs[i]>maxN) maxN = qs[i];
    }
    vector<int> pals;
    for(int x=1;x<=maxN;x++){
        int y=x, rev=0;
        while(y){ rev = rev*10 + (y%10); y/=10; }
        if(rev==x) pals.push_back(x);
    }
    vector<int> dp(maxN+1);
    dp[0]=1;
    for(int p: pals){
        for(int s=p;s<=maxN;s++){
            dp[s] += dp[s-p];
            if(dp[s] >= MOD) dp[s] -= MOD;
        }
    }
    for(int i=0;i<t;i++){
        cout<<dp[qs[i]]<<"\n";
    }
    return 0;
}