#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> p(n), s(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> s[i];

        bool ok = true;
        for (int i = 1; i < n && ok; ++i) if (p[i-1] % p[i] != 0) ok = false;
        for (int i = 0; i+1 < n && ok; ++i) if (s[i+1] % s[i] != 0) ok = false;
        if (!ok) {
            cout << "No\n";
            continue;
        }

        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            ll g = std::gcd(p[i], s[i]);
            ll l = (p[i] / g) * s[i];
            b[i] = l;
        }

        vector<ll> pref(n), suf(n);
        pref[0] = b[0];
        for (int i = 1; i < n; ++i) pref[i] = std::gcd(pref[i-1], b[i]);
        suf[n-1] = b[n-1];
        for (int i = n-2; i >= 0; --i) suf[i] = std::gcd(suf[i+1], b[i]);

        bool match = true;
        for (int i = 0; i < n; ++i) {
            if (pref[i] != p[i] || suf[i] != s[i]) { match = false; break; }
        }
        cout << (match ? "Yes\n" : "No\n");
    }
    return 0;
}