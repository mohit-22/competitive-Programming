#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 min_cost_to_group(const string &s, char ch) {
    vector<int> pos;
    pos.reserve(s.size());
    for (int i = 0; i < (int)s.size(); ++i) if (s[i] == ch) pos.push_back(i);
    int k = (int)pos.size();
    if (k <= 1) return 0;
    vector<int64> q(k);
    for (int i = 0; i < k; ++i) q[i] = (int64)pos[i] - i;
    sort(q.begin(), q.end());
    int64 median = q[k/2];
    int64 cost = 0;
    for (int i = 0; i < k; ++i) cost += llabs(q[i] - median);
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int64 cost_a = min_cost_to_group(s, 'a');
        int64 cost_b = min_cost_to_group(s, 'b');
        cout << min(cost_a, cost_b) << '\n';
    }
    return 0;
}
