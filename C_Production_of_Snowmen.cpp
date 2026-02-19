#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<bool> goodAB(n, true), goodBC(n, true);

        // Check all shifts x for a[p] < b[p + x]
        for (int x = 0; x < n; x++) {
            for (int p = 0; p < n; p++) {
                if (a[p] >= b[(p + x) % n]) {
                    goodAB[x] = false;
                    break;
                }
            }
        }

        // Check all shifts y for b[p] < c[p + y]
        for (int y = 0; y < n; y++) {
            for (int p = 0; p < n; p++) {
                if (b[p] >= c[(p + y) % n]) {
                    goodBC[y] = false;
                    break;
                }
            }
        }

        ll cntAB = 0, cntBC = 0;
        for (int i = 0; i < n; i++) {
            if (goodAB[i]) cntAB++;
            if (goodBC[i]) cntBC++;
        }

        ll answer = (ll)n * cntAB * cntBC;
        cout << answer << '\n';
    }

    return 0;
}
