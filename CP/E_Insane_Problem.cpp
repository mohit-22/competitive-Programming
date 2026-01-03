#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x,l1,r1,l2,r2;
        cin >> x>>l1>>r1>>l2>>r2;

        int y=0;
        int ans=0;
        while(pow(x,y)<=r2/l1){
            int mn = (l2+pow(x,y)-1)/pow(x,y);
            int mx = (r2)/pow(x,y);
            int range1 = max(l1,mn);
            int range2 = min(r1,mx);
            ans+=max(range2-range1+1,0ll);
            y++;
        }
        cout<<ans<<endl;
        
    }
    return 0;
} 