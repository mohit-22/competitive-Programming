#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int long long
const ll MOD = 1000000007LL;
const ll INF = (ll)9e18;

ll g(ll x) {
    if (x < 0) return -x;
    return x;
}



ll Radhe(int n, ll Ax, ll Ay, ll Bx, ll By, vector<ll>& xs, vector<ll>& ys){
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++) v.push_back({xs[i], ys[i]});
    sort(v.begin(), v.end());

    vector<ll> X,L,R;
    v.push_back({-1, -1});

    ll lo = v[0].second, hi = v[0].second;
    ll lastX = v[0].first;

    for (int i = 1; i <= n; i++) {
        if (v[i].first == lastX) {
            lo = min(lo, v[i].second);
            hi = max(hi, v[i].second);
        } else{
            X.push_back(lastX);
            L.push_back(lo);
            R.push_back(hi);

            if (i < n) {
                lastX = v[i].first;
                lo = hi = v[i].second;
            }
        }
    }

    v.pop_back();


    ll dpll=0, dprr=0;
    ll cx=Ax, ly=Ay, ry=Ay;

    for (int i = 0; i <X.size(); ++i) {
        ll dx = X[i] - cx;
        ll d = R[i] - L[i];

        ll nxt[2] = {LLONG_MAX, LLONG_MAX};
        ll cur_cst[2] = {dpll, dprr};
        ll cuy[2] = {ly, ry};

        for (int s = 0; s < 2; s++) {
            nxt[0] = min(nxt[0],cur_cst[s] + dx + min(g(cuy[s] - L[i]) + 2*d,g(cuy[s] - R[i]) + d));
            nxt[1] = min(nxt[1],cur_cst[s] + dx + min(g(cuy[s] - L[i]) + d, g(cuy[s] - R[i]) + 2*d));
        }

        dpll = nxt[0];
        dprr = nxt[1];
        cx = X[i];
        ly = L[i];
        ry = R[i];

    }


    ll tmp[2];
    tmp[0] = dpll + (Bx - cx) + g(ly - By);
    tmp[1] = dprr + (Bx - cx) + g(ry - By);

    return *min_element(tmp, tmp + 2);


}

int main(){


    int t; 
    cin>>t;
    while(t--){
        int n; 
        ll Ax,Ay,Bx,By;
        cin>>n>>Ax>>Ay>>Bx>>By;
        vector<ll> xs(n),ys(n);
        for(int i=0;i<n;i++) cin>>xs[i];
        for(int i=0;i<n;i++) cin>>ys[i];
        cout<<Radhe(n,Ax,Ay,Bx,By,xs,ys)<<endl;
    }
}
