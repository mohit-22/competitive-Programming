#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        ll S = 0;
        for(int i = 0; i < n; ++i) { cin >> a[i]; S += a[i]; }
        // Check divisibility
        if ((2 * S) % n != 0) {
            cout << 0 << '\n';
            continue;
        }
        ll target = (2 * S) / n;
        unordered_map<ll, ll> freq;
        freq.reserve(n * 2);
        for (ll x : a) ++freq[x];

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll x = a[i];
            --freq[x]; // don't pair with self or already counted indices
            ll need = target - x;
            if (freq.count(need)) ans += freq[need];
        }
        cout << ans << '\n';
    }
    return 0;
}