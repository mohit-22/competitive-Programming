#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int64 modpow(int64 a, int64 e){
    int64 r = 1 % MOD;
    while(e){
        if(e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        int64 sum = 0, sumsq = 0;
        for(int i = 0; i < n; ++i){
            int64 x;
            cin >> x;
            x %= MOD;
            sum = (sum + x) % MOD;
            sumsq = (sumsq + (x * x) % MOD) % MOD;
        }
        int64 numerator = ((sum * sum) % MOD - sumsq + MOD) % MOD;
        int64 denom = (int64)n * (n - 1) % MOD;
        int64 inv_denom = modpow(denom, MOD - 2);
        int64 answer = numerator * inv_denom % MOD;
        cout << answer << '\n';
    }
}