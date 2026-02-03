#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        unordered_map<long long, vector<int>> mp;
        mp.reserve(n * 2);
        auto key = [&](int x, int y)->long long { return ( (long long)x << 32 ) ^ (unsigned long long)y; };
        for (int i = 1; i <= n; ++i) mp[key(a[i], b[i])].push_back(i);

        vector<pair<int,int>> pairs;
        int center = -1;
        bool bad = false;

        vector<pair<int,int>> keys;
        keys.reserve(mp.size());
        for (auto &it : mp) {
            long long kk = it.first;
            int x = int(kk >> 32);
            int y = int((unsigned)kk);
            keys.emplace_back(x,y);
        }

        for (auto pr : keys) {
            int x = pr.first, y = pr.second;
            if (x > y) continue;
            long long k1 = key(x,y);
            if (x == y) {
                auto &v = mp[k1];
                int sz = (int)v.size();
                for (int i = 0; i + 1 < sz; i += 2) pairs.emplace_back(v[i], v[i+1]);
                if (sz % 2 == 1) {
                    if (center == -1) center = v.back();
                    else { bad = true; break; }
                }
            } else {
                long long k2 = key(y,x);
                auto it1 = mp.find(k1);
                auto it2 = mp.find(k2);
                int s1 = (it1 == mp.end() ? 0 : (int)it1->second.size());
                int s2 = (it2 == mp.end() ? 0 : (int)it2->second.size());
                if (s1 != s2) { bad = true; break; }
                if (s1 == 0) continue;
                auto &v1 = it1->second;
                auto &v2 = it2->second;
                for (int i = 0; i < s1; ++i) pairs.emplace_back(v1[i], v2[i]);
            }
        }

        if (bad) {
            cout << -1 << '\n';
            continue;
        }

        int m = (int)pairs.size();
        int needCenter = (n % 2 == 1 ? 1 : 0);
        if (needCenter && center == -1) { cout << -1 << '\n'; continue; }
        if (!needCenter && center != -1) { cout << -1 << '\n'; continue; }

        vector<int> target(n+1, 0);
        for (int i = 0; i < m; ++i) {
            int leftPos = i + 1;
            int rightPos = n - i;
            target[leftPos] = pairs[i].first;
            target[rightPos] = pairs[i].second;
        }
        if (needCenter) target[(n+1)/2] = center;

        vector<int> curAtPos(n+1), posOfIdx(n+1);
        for (int i = 1; i <= n; ++i) { curAtPos[i] = i; posOfIdx[i] = i; }

        vector<pair<int,int>> ops;
        ops.reserve(n);
        for (int i = 1; i <= n; ++i) {
            int desiredIdx = target[i];
            if (curAtPos[i] == desiredIdx) continue;
            int j = posOfIdx[desiredIdx];
            ops.emplace_back(i, j);
            int idx_i = curAtPos[i];
            int idx_j = curAtPos[j];
            swap(curAtPos[i], curAtPos[j]);
            posOfIdx[idx_i] = j;
            posOfIdx[idx_j] = i;
        }

        if ((int)ops.size() > n) {
            cout << -1 << '\n';
            continue;
        }

        cout << ops.size() << '\n';
        for (auto &p : ops) cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
