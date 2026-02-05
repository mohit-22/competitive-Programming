#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int total = 0;
        for (int v : a) total ^= v;
        if (total == 0) {
            cout << "YES\n";
            continue;
        }
        int pref = 0;
        bool found = false;
        for (int i = 0; i < n; ++i) {
            pref ^= a[i];
            if (pref == total) {
                int pref2 = 0;
                for (int j = i + 1; j < n; ++j) {
                    pref2 ^= a[j];
                    if (pref2 == total && j + 1 < n) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}