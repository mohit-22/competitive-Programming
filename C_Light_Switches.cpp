#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll maxa = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            maxa = max(maxa, a[i]);
        }

        int mod = 2 * k;
        vector<int> diff(mod + 1, 0);

        for (int i = 0; i < n; ++i) {
            int s = int(a[i] % mod);
            int end = s + k;
            if (end <= mod) {
                diff[s] += 1;
                diff[end] -= 1;
            } else {
                diff[s] += 1;
                diff[mod] -= 1;
                diff[0] += 1;
                diff[end % mod] -= 1;
            }
        }

        vector<int> cnt(mod, 0);
        int cur = 0;
        for (int r = 0; r < mod; ++r) {
            cur += diff[r];
            cnt[r] = cur;
        }

        vector<int> good;
        for (int r = 0; r < mod; ++r)
            if (cnt[r] == n) good.push_back(r);

        if (good.empty()) {
            cout << -1 << '\n';
            continue;
        }

        ll base = maxa;
        int base_r = int(base % mod);
        ll best = LLONG_MAX;
        for (int r : good) {
            ll candidate;
            if (r >= base_r) candidate = base + (r - base_r);
            else candidate = base + (mod - base_r) + r;
            best = min(best, candidate);
        }

        cout << best << '\n';
    }
    return 0;
}
