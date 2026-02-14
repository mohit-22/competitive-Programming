#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int64 n, x;
        cin >> n >> x;
        int64 ans = 0;
        int64 amax = min<int64>(n, max<int64>(0, x - 2));
        for (int64 a = 1; a <= amax; ++a) {
            int64 bmax = min<int64>(x - a - 1, n / a);
            if (bmax < 1) continue;
            for (int64 b = 1; b <= bmax; ++b) {
                int64 rem = n - a * b;
                if (rem < 0) break;
                int64 c1 = rem / (a + b);
                int64 c2 = x - a - b;
                int64 cm = min(c1, c2);
                if (cm >= 1) ans += cm;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}