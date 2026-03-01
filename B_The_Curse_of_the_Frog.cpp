#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        __int128 base = 0;
        long long max_gain = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            base += (__int128)(b - 1) * a;
            max_gain = max(max_gain, b * a - c);
        }

        if (base >= x) {
            cout << 0 << '\n';
            continue;
        }

        if (max_gain <= 0) {
            cout << -1 << '\n';
            continue;
        }

        __int128 need = (__int128)x - base;
        long long ans = (long long)((need + max_gain - 1) / max_gain);
        cout << ans << '\n';
    }

    return 0;
}