#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> divisors;
        for (int d = 1; d * 1LL * d <= n; ++d) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d != n / d) divisors.push_back(n / d);
            }
        }
        sort(divisors.begin(), divisors.end());
        int answer = n;
        for (int p : divisors) {
            vector<array<int,26>> counts(p);
            for (int i = 0; i < p; ++i) counts[i].fill(0);
            for (int i = 0; i < n; ++i) counts[i % p][s[i] - 'a']++;
            int sumMax = 0;
            for (int j = 0; j < p; ++j) {
                int best = 0;
                for (int c = 0; c < 26; ++c) if (counts[j][c] > best) best = counts[j][c];
                sumMax += best;
            }
            int mismatches = n - sumMax;
            if (mismatches <= 1) { answer = p; break; }
        }
        cout << answer << '\n';
    }
    return 0;
}