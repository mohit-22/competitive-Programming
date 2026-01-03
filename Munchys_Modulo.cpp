

#include <bits/stdc++.h>

using namespace std;



using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<ll> A(N);
        
        
        for (auto &x : A) cin >> x;
        
        
        sort(A.begin(), A.end(), greater<ll>());

        ll M = A[0];
        ll r1 = M % (A[1] + A[2]);
        
        
        ll r2 = A[1] % (M + A[2]);
        ll r3 = A[2] % (M + A[1]);
        ll best = max({r1, r2, r3});

        ll half = M / 2;
        ll bestSum = LLONG_MAX;

        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ll S = A[i] + A[j];
                if (S > half && S <= M && S < bestSum) {
                    bestSum = S;
                }
            }
        }
        if (bestSum != LLONG_MAX) {
            best = max(best, M - bestSum);
        }

        cout << best << "\n";
    }
    return 0;
}
