#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        const int B = 30; // ai < 2^30
        vector<int> ones(B, 0);
        for (int x : a)
            for (int b = 0; b < B; ++b)
                if ((x >> b) & 1) ++ones[b];

        ll best = 0;
        for (int x : a) {
            unsigned long long score = 0;
            for (int b = 0; b < B; ++b) {
                unsigned long long bitval = 1ull << b;
                if ((x >> b) & 1) {
                    score += (unsigned long long)(n - ones[b]) * bitval;
                } else {
                    score += (unsigned long long)ones[b] * bitval;
                }
            }
            best = max(best, (ll)score);
        }
        cout << best << '\n';
    }
    return 0;
}
