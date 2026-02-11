#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> cnt(n+5, 0);
        for (int x : a) if (x < (int)cnt.size()) cnt[x]++;
        // p = first i with cnt[i] == 0
        int p = 0;
        while (p < (int)cnt.size() && cnt[p] > 0) ++p;
        // gather indices with cnt == 1
        vector<int> ones;
        for (int i = 0; i < (int)cnt.size(); ++i) if (cnt[i] == 1) ones.push_back(i);
        int q = INT_MAX;
        if ((int)ones.size() >= 2) q = ones[1];
        int ans = min(p, q == INT_MAX ? INT_MAX : q);
        cout << ans << '\n';
    }
    return 0;
}