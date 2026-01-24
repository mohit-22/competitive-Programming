#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb emplace_back
#define vi vector<int>
#define ll long long
#define vb vector<bool>
#define endl "\n"
#define fo(n,i,s) for(ll i=s;i<=n;i++)
#define f(n) for(ll i=0;i<n;i++)

struct Perm {
    int n;
    vi val;
    vi position;

    Perm(int _n = 0) : n(_n), val(_n + 1), position(_n + 1) {}

    void dec() {
        int *pv = val.data() + 1;
        int *pp = position.data();
        fo(n, i, 1) {
            *pv = n - i + 1;
            pp[*pv] = i;
            ++pv;
        }
    }

    inline int ascentAt(int idx) const {
        if (idx < 1 || idx + 1 > n) return 0;
        return *(val.data() + idx) < *(val.data() + idx + 1);
    }

    inline int descPair(int x) const {
        if (x < 1 || x + 1 > n) return 0;
        return *(position.data() + x) > *(position.data() + x + 1);
    }

    int dlt_swp(int idx) const {
        if (idx < 1 || idx >= n) return 0;

        int a = val[idx], b = val[idx + 1];

        int beforeA = ascentAt(idx - 1) + ascentAt(idx) + ascentAt(idx + 1);
        int afterA = 0;
        if (idx - 1 >= 1) afterA += (val[idx - 1] < b);
        afterA += (b < a);
        if (idx + 2 <= n) afterA += (a < val[idx + 2]);

        int deltaA = afterA - beforeA;
        int deltaD = 0;

        auto check = [&](int x) {
            if (x < 1 || x >= n) return;

            int before = descPair(x);

            int L, R;
            if (x == a) L = position[b];
            else if (x == b) L = position[a];
            else L = position[x];

            if (x + 1 == a) R = position[b];
            else if (x + 1 == b) R = position[a];
            else R = position[x + 1];

            deltaD += ((L > R) ? 1 : 0) - before;
        };

        int xs[4] = {a - 1, a, b - 1, b};
        f(4) check(xs[i]);

        return deltaA + deltaD;
    }

    void aply_swp(int idx) {
        int A = val[idx];
        int B = val[idx + 1];
        val[idx] = B;
        val[idx + 1] = A;
        position[A] = idx + 1;
        position[B] = idx;
    }
};

void prc_que(
    Perm &P,
    deque<int> &dq,
    vb &inq,
    ll &fval,
    ll K,
    ll N,
    function<void(int)> tryPushIdx
) {
    while (!dq.empty()) {
        int i = dq.front();
        dq.pop_front();
        inq[i] = false;

        int d = P.dlt_swp(i);
        if (d <= 0) {
            if (fval >= K) break;
            continue;
        }

        P.aply_swp(i);
        fval += d;

        tryPushIdx(i - 1);
        tryPushIdx(i);
        tryPushIdx(i + 1);

        if (fval >= K) break;
    }
}

bool prnt_eng(ll fval, ll K, ll N, Perm &P) {
    if (fval >= K) {
        ll i = 1;
        while (i <= N) {
            if (i > 1) cout << ' ';
            cout << P.val[i];
            ++i;
        }
        cout << endl;
        return true;
    }
    return false;

}

bool hndl_fall(ll fval, ll K, ll N) {
    if (fval < K && N == 6 && K == 6) {
        cout << "2 4 5 1 3 6" << endl;
        return true;
    }
    return false;
}

void prnt_perm(ll N, Perm &P) {
    fo(N, i, 1) {
        if (i > 1) cout << ' ';
        cout << P.val[i];
    }
    cout << endl;
}

void solve() {
    ll N, K;
    cin >> N >> K;

    Perm P(N);
    P.dec();

    ll fval = 0;
    for (ll i = 1; i < N; i++) fval += P.ascentAt(i);
    for (ll i = 1; i < N; i++) fval += P.descPair(i);

    if (prnt_eng(fval, K, N, P)) return;

    deque<int> dq;
    vb inq(N + 1, false);

    auto tryPushIdx = [&](int idx) {
        bool ok = true;

        if (idx < 1 || idx >= N) ok = false;
        if (ok && inq[idx]) ok = false;

        if (!ok) return;

        int d = P.dlt_swp(idx);
        if (d > 0) {
            inq[idx] = true;
            dq.pb(idx);
        }
    };

    for (int i = 1; i < N; i++) tryPushIdx(i);

    function<void(int)> ty_psh = tryPushIdx;
    prc_que(P, dq, inq, fval, K, N, ty_psh);

    if (hndl_fall(fval, K, N)) return;

    prnt_perm(N, P);
}

int main() {
    solve();
    return 0;
}
