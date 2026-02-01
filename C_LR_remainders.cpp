#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 modMul(int64 a, int64 b, int64 mod) {
    return (a % mod) * (b % mod) % mod;
}

int64 modPow(int64 a, long long e, int64 mod) {
    int64 res = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) res = modMul(res, a, mod);
        a = modMul(a, a, mod);
        e >>= 1;
    }
    return res;
}

long long egcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int64 modInv(int64 a, int64 m) {
    long long x, y;
    long long g = egcd(a, m, x, y);
    if (g != 1) return -1;
    long long res = (x % m + m) % m;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        int64 m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        string s;
        cin >> s;
        if (m == 1) {
            for (int i = 0; i < n; ++i) cout << 0 << (i + 1 == n ? '\n' : ' ');
            continue;
        }
        int64 mm = m;
        vector<int64> primes;
        for (int64 p = 2; p * p <= mm; ++p) {
            if (mm % p == 0) {
                primes.push_back(p);
                while (mm % p == 0) mm /= p;
            }
        }
        if (mm > 1) primes.push_back(mm);
        int k = (int)primes.size();
        vector<vector<int>> exps(n, vector<int>(k, 0));
        vector<int64> rest(n, 1 % m);
        vector<int64> totalCnt(k, 0);
        int64 rem = 1 % m;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int64 cur = x;
            for (int j = 0; j < k; ++j) {
                int64 p = primes[j];
                while (cur % p == 0) {
                    exps[i][j] += 1;
                    cur /= p;
                }
                totalCnt[j] += exps[i][j];
            }
            rest[i] = cur % m;
            rem = modMul(rem, rest[i], m);
        }
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i) {
            int64 cur = rem;
            for (int j = 0; j < k; ++j) {
                if (totalCnt[j] > 0) cur = modMul(cur, modPow(primes[j], totalCnt[j], m), m);
            }
            cout << cur << (i + 1 == n ? '\n' : ' ');
            int idx;
            if (s[i] == 'L') idx = l++;
            else idx = r--;
            for (int j = 0; j < k; ++j) totalCnt[j] -= exps[idx][j];
            if (rest[idx] != 1 % m) {
                int64 inv = modInv(rest[idx], m);
                rem = modMul(rem, inv, m);
            } else {
                // rest[idx] == 1 → multiplying by 1^-1 has no effect
            }
        }
    }
    return 0;
}