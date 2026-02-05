#include <bits/stdc++.h>
using namespace std;

long long next_pow2_gt(long long x) {
    long long p = 1;
    while (p <= x) p <<= 1;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long ans;
        if (n & 1) ans = n;
        else ans = next_pow2_gt(n) - 1;

        vector<int> p(n);
        iota(p.begin(), p.end(), 1);

        auto is_pow2 = [&](int x) {
            return (x & (x - 1)) == 0;
        };

        if (n & 1) {
            swap(p[0], p[n - 4]);
            swap(p[2], p[n - 3]);
        } else if (is_pow2(n)) {
            swap(p[0], p[n - 5]);
            swap(p[2], p[n - 4]);
        } else {
            long long temp = 1;
            while (temp < n) temp <<= 1;
            long long prev_pow = temp >> 1;
            int m = (int)(prev_pow - 1);
            swap(p[m - 1], p[n - 3]);
            swap(p[n - 1], p[n - 3]);
        }

        cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }
    return 0;
}
