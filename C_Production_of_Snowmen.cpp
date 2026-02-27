#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n), C(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        for (int i = 0; i < n; ++i) cin >> C[i];

        auto countGoodShifts = [&](const vector<int>& X, const vector<int>& Y) -> int {
            int cnt = 0;
            for (int s = 0; s < n; ++s) {
                bool ok = true;
                for (int u = 0; u < n; ++u) {
                    if (!(X[u] < Y[(u + s) % n])) { ok = false; break; }
                }
                if (ok) ++cnt;
            }
            return cnt;
        };

        int cntAB = countGoodShifts(A, B);
        int cntBC = countGoodShifts(B, C);
        ll ans = (ll) n * cntAB * cntBC;
        cout << ans << '\n';
    }
}