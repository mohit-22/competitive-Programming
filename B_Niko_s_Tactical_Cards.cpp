#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int64> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int64 cur_min = 0, cur_max = 0;
        for (int i = 0; i < n; ++i) {
            int64 red_max = cur_max - a[i];
            int64 red_min = cur_min - a[i];
            int64 blue_max = b[i] - cur_min; // note using min for blue -> gives max
            int64 blue_min = b[i] - cur_max; // using max for blue -> gives min

            int64 nxt_max = max(red_max, blue_max);
            int64 nxt_min = min(red_min, blue_min);
            cur_max = nxt_max;
            cur_min = nxt_min;
        }
        cout << cur_max << '\n';
    }
    return 0;
}