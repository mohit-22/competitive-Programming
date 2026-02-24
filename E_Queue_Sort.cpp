#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int fm = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[fm]) fm = i;
        }
        bool ok = true;
        for (int i = fm + 1; i < n; ++i) {
            if (a[i] < a[i - 1]) { ok = false; break; }
        }

        if (!ok) cout << -1 << '\n';
        else cout << fm << '\n';
    }
}