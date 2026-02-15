#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canFinish(const vector<pair<ll,ll>>& segs, ll k){
    ll curL = 0, curR = 0;
    for(const auto &p : segs){
        ll l = p.first, r = p.second;
        ll newL = max(l, curL - k);
        ll newR = min(r, curR + k);
        if(newL > newR) return false;
        curL = newL;
        curR = newR;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<pair<ll,ll>> segs(n);
        for(int i=0;i<n;++i) cin>>segs[i].first>>segs[i].second;
        ll lo = 0, hi = (ll)4e18;
        while(lo < hi){
            ll mid = lo + (hi - lo) / 2;
            if(canFinish(segs, mid)) hi = mid;
            else lo = mid + 1;
        }
        cout<<lo<<"\n";
    }
    return 0;
}