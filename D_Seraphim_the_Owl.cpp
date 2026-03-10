#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        ll pref = 0;
        ll bSum = 0;
        int limit = n - m;
        for(int i = 0; i < limit; ++i) {
            if(a[i] < b[i]) {
                pref += bSum + a[i];
                bSum = 0;
            } else {
                bSum += b[i];
            }
        }
        const ll INF = (ll)4e18;
        ll ans = INF;
        for(int i = limit; i < n; ++i) {
            ans = min(ans, pref + bSum + a[i]);
            bSum += b[i];
        }
        cout << ans << '\n';
    }
}