#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

#include <vector>
#include <string>
#include <functional>

using namespace std;

vector<string> enumerate_strings_bfs(int L) {
    vector<string> res;
    queue<string> q;
    q.push(string());
    while (!q.empty()) {
        string s = q.front(); q.pop();
        if ((int)s.size() > L) continue;
        res.push_back(s);
        if ((int)s.size() == L) continue;
        q.push(s + '0');
        q.push(s + '1');
    }
    return res;
}

// Precomputed maps:
static vector<string> smallStrings; // length <= 4
static unordered_map<string,int> smallIndex;
static vector<string> bigStrings;   // length <= 8
static unordered_map<string,int> bigIndex;
// For each big string id, a vector of (final small-string-id, cost) outcomes:
static vector<vector<pair<int,ll>>> reduceToSmall;

// Recursive reduction memo (for big strings)
static unordered_map<string, unordered_map<string,ll>> reduceMemo;

unordered_map<string,ll> reduce_all_final(const string &s) {
    auto it = reduceMemo.find(s);
    if (it != reduceMemo.end()) return it->second;
    unordered_map<string,ll> best;
    // If no triple exists, base: s -> 0
    int m = (int)s.size();
    bool any = false;
    // try all triples
   // Variant B
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            for (int k = j+1; k < m; ++k) {
                if (s[i] == s[j] && s[j] == s[k]) {
                    any = true;
                    int add = min(k - j, j - i);
                    string ns = s;
                    // erase from right to left so indices remain valid
                    ns.erase(k, 1);
                    ns.erase(j, 1);
                    ns.erase(i, 1);
                    auto rec = reduce_all_final(ns);
                    for (auto &pr : rec) {
                        const string &finals = pr.first;
                        ll cost = pr.second + add;
                        auto it2 = best.find(finals);
                        if (it2 == best.end() || cost < it2->second) best[finals] = cost;
                    }
                }
            }
        }
    }

    if (!any) {
        best[s] = 0;
    }
    reduceMemo[s] = best;
    return reduceMemo[s];
}

void precompute_reductions() {
    // build smallStrings and bigStrings and indices
    smallStrings = enumerate_strings_bfs(4); // sizes 0..4
    smallIndex.clear();
    for (int i = 0; i < (int)smallStrings.size(); ++i) smallIndex[smallStrings[i]] = i;
    bigStrings = enumerate_strings_bfs(8); // sizes 0..8
    bigIndex.clear();
    for (int i = 0; i < (int)bigStrings.size(); ++i) bigIndex[bigStrings[i]] = i;

    reduceMemo.clear();
    reduceToSmall.assign(bigStrings.size(), {});
    // For each big string compute reductions
    for (size_t i = 0; i < bigStrings.size(); ++i) {
        const string &bs = bigStrings[i];
        auto mp = reduce_all_final(bs); // map final_string -> min cost
        vector<pair<int,ll>> vec;
        vec.reserve(mp.size());
        for (auto &pr : mp) {
            const string &finals = pr.first;
            ll c = pr.second;
            if (finals.size() <= 4) {
                auto it = smallIndex.find(finals);
                if (it != smallIndex.end()) vec.emplace_back(it->second, c);
            }
        }
        reduceToSmall[i] = std::move(vec);
    }

}

// Segment tree node: vector<ll> costs for each small string
struct Node {
    vector<ll> cost; // size = smallStrings.size()
    Node() { cost.assign(smallStrings.size(), INF); }
};

// merge two node states
Node mergeNodes(const Node &A, const Node &B) {
    Node R;
    int S = (int)smallStrings.size();
    // iterate over only finite states to speed up
    vector<int> aIdx, bIdx;
    aIdx.reserve(S); bIdx.reserve(S);
    for (int i = 0; i < S; ++i) if (A.cost[i] < INF) aIdx.push_back(i);
    for (int j = 0; j < S; ++j) if (B.cost[j] < INF) bIdx.push_back(j);
    for (int ia : aIdx) {
        const string &sL = smallStrings[ia];
        for (int jb : bIdx) {
            const string &sR = smallStrings[jb];
            string big = sL + sR; // length <= 8
            int bigId = bigIndex[big];
            ll baseCost = A.cost[ia] + B.cost[jb];
            // iterate precomputed final small outcomes
            for (auto &pr : reduceToSmall[bigId]) {
                int finalId = pr.first;
                ll add = pr.second;
                ll cand = baseCost + add;
                if (cand < R.cost[finalId]) R.cost[finalId] = cand;
            }
        }
    }
    return R;
}

struct SegTree {
    int n;
    vector<Node> st;
    SegTree() {}
    SegTree(const vector<int> &arr) { build(arr); }
    void build(const vector<int> &arr) {
        n = (int)arr.size();
        st.assign(4*n, Node());
        buildRec(1,0,n-1,arr);
    }
    void buildRec(int p, int l, int r, const vector<int> &arr) {
        if (l == r) {
            // leaf: only single-character string has cost 0
            string s(1, arr[l] ? '1' : '0');
            int id = smallIndex[s];
            st[p].cost[id] = 0;
            return;
        }
        int m = (l + r) >> 1;
        buildRec(p<<1, l, m, arr);
        buildRec(p<<1|1, m+1, r, arr);
        st[p] = mergeNodes(st[p<<1], st[p<<1|1]);
    }
    // query returns Node for range [L,R]
    Node query(int L, int R) { return queryRec(1,0,n-1,L,R); }
    Node queryRec(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) return st[p];
        int m = (l + r) >> 1;
        if (R <= m) return queryRec(p<<1, l, m, L, R);
        if (L > m)  return queryRec(p<<1|1, m+1, r, L, R);
        Node left = queryRec(p<<1, l, m, L, R);
        Node right = queryRec(p<<1|1, m+1, r, L, R);
        return mergeNodes(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_reductions();

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        // prefix counts
        vector<int> pref0(n+1,0), pref1(n+1,0);
        for (int i = 1; i <= n; ++i) {
            pref0[i] = pref0[i-1] + (a[i-1]==0);
            pref1[i] = pref1[i-1] + (a[i-1]==1);
        }
        // build segment tree
        SegTree st;
        st.build(a);

        // id of empty string in smallStrings
        int emptyId = smallIndex[string("")];

        for (int qi = 0; qi < q; ++qi) {
            int l, r; cin >> l >> r; --l; --r;
            int cnt0 = pref0[r+1] - pref0[l];
            int cnt1 = pref1[r+1] - pref1[l];
            if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
                cout << -1 << '\n';
                continue;
            }
            Node ansNode = st.query(l, r);
            ll ans = ansNode.cost[emptyId];
            if (ans >= INF/2) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
    return 0;
}
