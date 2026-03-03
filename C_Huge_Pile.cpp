#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int solve_rec(ll n, ll k, unordered_map<ll,int> &memo) {
    if (n < k) return INF;
    if (n == k) return 0;
    auto it = memo.find(n);
    if (it != memo.end()) return it->second;
    ll left = n / 2;
    ll right = n - left;
    int ans = INF;
    if (k <= left) ans = min(ans, 1 + solve_rec(left, k, memo));
    if (k <= right) ans = min(ans, 1 + solve_rec(right, k, memo));
    memo[n] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        unordered_map<ll,int> memo;
        int res = solve_rec(n, k, memo);
        if (res >= INF) cout << -1 << '\n';
        else cout << res << '\n';
    }
    return 0;
}