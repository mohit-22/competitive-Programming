#include <bits/stdc++.h>
using namespace std;

void solve_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= n) pos[a[i]].push_back(i);
    }

    vector<int> sel;
    sel.reserve(n);
    for (int val = 1; val <= n; ++val) {
        int take = min((int)pos[val].size(), k);
        for (int j = 0; j < take; ++j) sel.push_back(pos[val][j]);
    }

    int m = (int)sel.size() - (int)sel.size() % k;

    vector<int> ans(n, 0);
    for (int i = 0; i < m; ++i) {
        ans[sel[i]] = (i % k) + 1;
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve_case();
    return 0;
}