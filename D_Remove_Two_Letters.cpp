#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const ll MOD1 = 1000000007LL;
    const ll MOD2 = 1000000009LL;
    const ll BASE = 91138233LL;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<ll> p1(n+1), p2(n+1);
        p1[0] = p2[0] = 1;

        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i-1] * BASE) % MOD1;
            p2[i] = (p2[i-1] * BASE) % MOD2;
        }

        vector<ll> h1(n+1,0), h2(n+1,0);

        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;
            h1[i+1] = (h1[i] * BASE + val) % MOD1;
            h2[i+1] = (h2[i] * BASE + val) % MOD2;
        }

        auto getHash = [&](int l, int r) {
            if (l > r) return pair<ll,ll>{0,0};
            int len = r - l + 1;
            ll x1 = (h1[r+1] - (h1[l] * p1[len]) % MOD1 + MOD1) % MOD1;
            ll x2 = (h2[r+1] - (h2[l] * p2[len]) % MOD2 + MOD2) % MOD2;
            return pair<ll,ll>{x1, x2};
        };

        unordered_set<ull> seen;
        seen.reserve(n*2);

        for (int i = 0; i <= n-2; i++) {
            auto pref = getHash(0, i-1);
            auto suf = getHash(i+2, n-1);

            int lenSuf = n - i - 2;

            ll combined1 = ((pref.first * p1[lenSuf]) % MOD1 + suf.first) % MOD1;
            ll combined2 = ((pref.second * p2[lenSuf]) % MOD2 + suf.second) % MOD2;

            ull key = ((ull)combined1 << 32) | (ull)combined2;
            seen.insert(key);
        }

        cout << seen.size() << '\n';
    }
}