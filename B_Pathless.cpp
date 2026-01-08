#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int targetGlobal;
int cnt0, cnt1, cnt2, N;
unordered_set<ull> visitedState;
vector<int> solutionSeq;
vector<char> maskRep;

inline ull packKey(int c0, int c1, int c2, int last, int mask) {
    return ((ull)c0) | (((ull)c1) << 6) | (((ull)c2) << 12) | (((ull)last) << 18) | (((ull)mask) << 20);
}

void buildMaskRep(int target) {
    maskRep.assign(32, 0);
    for (int mask = 0; mask < 32; ++mask) {
        if (target == 0) { maskRep[mask] = 1; continue; }
        vector<int> coins;
        for (int d = 1; d <= 4; ++d) if (mask & (1 << d)) coins.push_back(d);
        if (coins.empty()) { maskRep[mask] = 0; continue; }
        bool has1 = false;
        for (int c : coins) if (c == 1) { has1 = true; break; }
        if (has1) { maskRep[mask] = 1; continue; }
        vector<char> dp(target + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int x = c; x <= target; ++x) if (!dp[x] && dp[x - c]) dp[x] = 1;
        }
        maskRep[mask] = dp[target];
    }
}

bool dfs_search(int r0, int r1, int r2, int last, int mask, vector<int> &seq) {
    ull key = packKey(r0, r1, r2, last, mask);
    if (visitedState.find(key) != visitedState.end()) return false;
    if (maskRep[mask]) { 
        visitedState.insert(key);
        return false;
    }
    if (r0 + r1 + r2 == 0) {
        if (!maskRep[mask]) {
            solutionSeq = seq;
            return true;
        } else {
            visitedState.insert(key);
            return false;
        }
    }

  
    if (r0 > 0) {
        seq.push_back(0);
        int newMask = mask | (1 << (last + 0));
        if (dfs_search(r0 - 1, r1, r2, 0, newMask, seq)) return true;
        seq.pop_back();
    }
    if (r1 > 0) {
        seq.push_back(1);
        int newMask = mask | (1 << (last + 1));
        if (dfs_search(r0, r1 - 1, r2, 1, newMask, seq)) return true;
        seq.pop_back();
    }
    if (r2 > 0) {
        seq.push_back(2);
        int newMask = mask | (1 << (last + 2));
        if (dfs_search(r0, r1, r2 - 1, 2, newMask, seq)) return true;
        seq.pop_back();
    }

    visitedState.insert(key);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, s;
        cin >> n >> s;
        N = n;
        vector<int> a(n);
        cnt0 = cnt1 = cnt2 = 0;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) ++cnt0;
            else if (a[i] == 1) ++cnt1;
            else ++cnt2;
            total += a[i];
        }

        if (s < total) {
            bool firstOut = true;
            for (int i = 0; i < cnt0; ++i) { if (!firstOut) cout << ' '; cout << 0; firstOut = false; }
            for (int i = 0; i < cnt1; ++i) { if (!firstOut) cout << ' '; cout << 1; firstOut = false; }
            for (int i = 0; i < cnt2; ++i) { if (!firstOut) cout << ' '; cout << 2; firstOut = false; }
            cout << '\n';
            continue;
        }
        if (s == total) {
            cout << -1 << '\n';
            continue;
        }

        int target = s - total;
        targetGlobal = target;
        buildMaskRep(target);

        bool found = false;
        solutionSeq.clear();

        for (int startVal = 0; startVal <= 2 && !found; ++startVal) {
            int r0 = cnt0, r1 = cnt1, r2 = cnt2;
            if ((startVal == 0 && r0 == 0) || (startVal == 1 && r1 == 0) || (startVal == 2 && r2 == 0)) continue;
            if (startVal == 0) --r0;
            else if (startVal == 1) --r1;
            else --r2;

            visitedState.clear();
            vector<int> seq;
            seq.push_back(startVal);
            int initMask = 0;
            if (dfs_search(r0, r1, r2, startVal, initMask, seq)) {
                found = true;
                break;
            }
        }

        if (!found) cout << -1 << '\n';
        else {
            for (int i = 0; i < (int)solutionSeq.size(); ++i) {
                if (i) cout << ' ';
                cout << solutionSeq[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
