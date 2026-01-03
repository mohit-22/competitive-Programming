#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> arr(n);
        long long s = 0, ss = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
            ss += arr[i] * arr[i];
        }

        long long a = 4 * n;
        long long b = 4 * s;
        long long c = ss - m;

        // Calculate discriminant
        __int128 D = (__int128)b * b - 4LL * a * c;

        if (D < 0) {
            cout << "No real solution\n";
            continue;
        }

        // Take square root of D safely
        double sqrtD = sqrt((double)D);

        double x = (-1.0 * b + sqrtD) / (2.0 * a);
        double y = (-1.0 * b - sqrtD) / (2.0 * a);

        if (x > 0 && floor(x) == x) cout << (long long)x << "\n";
        else cout << (long long)y << "\n";
    }
    return 0;
}
