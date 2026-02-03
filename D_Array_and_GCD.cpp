#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXP = 400000;
    const int SIEVE_LIMIT = 6500000;

    vector<char> is_composite(SIEVE_LIMIT + 1, 0);
    vector<int> primes;
    primes.reserve(MAXP + 5);

    for (int i = 2; i <= SIEVE_LIMIT && (int)primes.size() < MAXP; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            if ((ll)i * i <= SIEVE_LIMIT) {
                for (ll j = 1LL * i * i; j <= SIEVE_LIMIT; j += i) {
                    is_composite[(int)j] = 1;
                }
            }
        }
    }

    vector<ll> prefP(primes.size() + 1, 0);
    for (size_t i = 0; i < primes.size(); ++i) {
        prefP[i + 1] = prefP[i] + primes[i];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        vector<ll> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + a[i];
        }

        int best_m = 1;
        for (int m = n; m >= 1; --m) {
            ll need = prefP[m];
            ll have = suffix[n - m];
            if (have >= need) {
                best_m = m;
                break;
            }
        }

        cout << (n - best_m) << '\n';
    }

    return 0;
}
