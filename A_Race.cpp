#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;
 
        int l = min(x, y);
        int r = max(x, y);
 
        if (a > l && a < r) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}