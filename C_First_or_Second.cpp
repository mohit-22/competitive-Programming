#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        ll f = 0;
        ll s;
        cin >> s;           // a1
        for (int i = 1; i < n; ++i) {
            ll x; cin >> x; // next element
            f = max(f - x, s);
            s += ll(abs(x));
        }
        cout << f << '\n';
    }
    return 0;
}