#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int half = k / 2;
        if (k == n) {
            int ans = half + 1;
            for (int i = 1; i < n; i += 2) {
                int expected = (i + 1) / 2 ;
                if (a[i] != expected) { ans = expected; break; }
            }
            cout << ans << '\n';
        } else {
            int limit = n - k + 1;
            bool found_not_one = false;
            for (int i = 1; i <= limit; ++i) {
                if (a[i] != 1) { found_not_one = true; break; }
            }
            cout << (found_not_one ? 1 : 2) << '\n';
        }
    }
    return 0;
}