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
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (n <= 3) {
            cout << 0 << '\n';
            continue;
        }

        int leaf_count = 0;
        for (int u = 1; u <= n; ++u) {
            if ((int)g[u].size() == 1) ++leaf_count;
        }

        int mx = 0;
        for (int u = 1; u <= n; ++u) {
            int cnt = 0;
            for (int v : g[u]) {
                if ((int)g[v].size() == 1) ++cnt;
            }
            mx = max(mx, cnt);
        }

        cout << (leaf_count - mx) << '\n';
    }
    return 0;
}
