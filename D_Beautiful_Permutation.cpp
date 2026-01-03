// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll ask(int type, int l, int r) {
//     cout << type << " " << l << " " << r << endl;
//     cout.flush();
//     ll ans;
//     if (!(cin >> ans)) exit(0);
//     if (ans == -1) exit(0);
//     return ans;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     if (!(cin >> t)) return 0;
//     while (t--) {
//         int n; cin >> n;

//         ll sp = ask(1, 1, n);
//         ll sa = ask(2, 1, n);
//         int len = (int)(sa - sp);

//         int L = 1, R = n + 1; 
//         while (L < R) {
//             int mid = (L + R) / 2;
//             ll su_p = ask(1, mid, n);
//             ll su_a = ask(2, mid, n);
//             ll diff = su_a - su_p; 
//             if (diff == 0) R = mid;
//             else L = mid + 1;
//         }
//         int r = L - 1;
//         int l = r - len + 1;
//         cout << "! " << l << " " << r << endl;
//         cout.flush();
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 query_int(int type, int l, int r) {
    printf("%d %d %d\n", type, l, r);
    fflush(stdout);
    int64 ans;
    if (scanf("%lld", &ans) != 1) {
        // no response from judge -> terminate
        exit(0);
    }
    if (ans == -1) exit(0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    if (scanf("%d", &tests) != 1) return 0;
    while (tests--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;

        // get total sums to compute block length
        int64 totalP = query_int(1, 1, n);
        int64 totalA = query_int(2, 1, n);
        int blockLen = (int)(totalA - totalP); // r - l + 1

        // binary search for first prefix containing modified value
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int64 prefP = query_int(1, 1, mid);
            int64 prefA = query_int(2, 1, mid);
            int64 delta = prefA - prefP;
            if (delta == 0) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        int left = lo;
        int right = left + blockLen - 1;
        printf("! %d %d\n", left, right);
        fflush(stdout);
    }
    return 0;
}

