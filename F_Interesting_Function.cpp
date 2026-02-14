#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll R = r - 1;
        ll L = l;
        ll ans = r - l;
        ll base = 10;
        while(true){
            ll target = base - 1;
            if(target > R) break;
            ll mod = base;
            ll rem = L % mod;
            ll add = (target - rem + mod) % mod;
            ll first = L + add;
            if(first <= R){
                ll cnt = (R - first) / mod + 1;
                ans += cnt;
            }
            base *= 10;
        }
        cout << ans << '\n';
    }
    return 0;
}