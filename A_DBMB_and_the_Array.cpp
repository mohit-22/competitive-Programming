#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long s, x;
        cin >> n >> s >> x;
        long long sumA = 0;
        for (int i = 0; i < n; ++i) {
            long long v; cin >> v;
            sumA += v;
        }
        if (s >= sumA && (s - sumA) % x == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}