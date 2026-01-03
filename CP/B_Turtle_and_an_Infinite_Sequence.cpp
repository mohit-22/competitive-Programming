#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int mn = max(0ll,n-m);
        int mx = n+m;

        int val=0;
        int ans=0;
        for(int i=0 ; i<=32 ; i++){
            if(mx-mn>=(1ll<<i)){
                ans+=(1ll<<i);
            }
            else if(((mn >> i) & 1)){
                ans+=(1ll<<i);
            }
            else if((mx>>i)&1){
                ans+=(1ll<<i);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}