#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> facts;
    {
        long long f = 1;
        for (int i = 0; ; ++i) {
            if (i == 0) f = 1;
            else f *= i;
            if (f > (long long)1e12) break;
            facts.push_back(f);
        }
        sort(facts.begin(), facts.end());
        facts.erase(unique(facts.begin(), facts.end()), facts.end());
    }
    int m = (int)facts.size();
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        int best = INT_MAX;
        int totalMasks = 1 << m;
        for (int mask = 0; mask < totalMasks; ++mask) {
            long long sum = 0;
            unsigned long long usedMask = 0;
            int cntFact = 0;
            bool overflow = false;
            for (int i = 0; i < m; ++i) if (mask & (1 << i)) {
                long long v = facts[i];
                sum += v;
                if (sum > n) { overflow = true; break; }
                ++cntFact;
                if ((v & (v - 1)) == 0) {
                    int bit = __builtin_ctzll((unsigned long long)v);
                    usedMask |= (1ULL << bit);
                }
            }
            if (overflow) continue;
            long long rem = n - sum;
            if (rem < 0) continue;
            if ((rem & (long long)usedMask) != 0) continue;
            int add = __builtin_popcountll((unsigned long long)rem);
            best = min(best, cntFact + add);
        }
        if (best == INT_MAX) cout << -1 << '\n';
        else cout << best << '\n';
    }
    return 0;
}