#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 1; i <= n-2; i += 2) { // i is 1-based index 2,4,... -> zero-based 1,3,...
            if (a[i] != a[i+1]) { ok = false; break; }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
