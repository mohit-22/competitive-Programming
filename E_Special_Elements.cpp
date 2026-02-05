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
        
        vector<int> cnt(n + 1, 0);
        for (int x : a) if (x <= n) ++cnt[x];
        
        vector<char> special(n + 1, 0);
        
        for (int l = 0; l < n; ++l) {
            int sum = a[l];
            for (int r = l + 1; r < n; ++r) {
                sum += a[r];
                if (sum > n) break;
                if (cnt[sum]) special[sum] = 1;
            }
        }
        
        int answer = 0;
        for (int val = 1; val <= n; ++val) if (special[val]) answer += cnt[val];
        cout << answer << '\n';
    }
    return 0;
}