#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int n = (int)a.size();
        int m = (int)b.size();
        int maxLen = 0;
        for(int i = 0; i < m; ++i) {
            int p = i;
            for(int j = 0; j < n && p < m; ++j) {
                if(a[j] == b[p]) ++p;
            }
            maxLen = max(maxLen, p - i);
            if(maxLen == m) break;
        }
        int ans = n + m - maxLen;
        cout << ans << '\n';
    }
    return 0;
}