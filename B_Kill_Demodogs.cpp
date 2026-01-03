// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// const int MOD = 1e9 + 7;

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         int s = (n * n) % MOD;
//         int x = n - 1;
//         int val = (n * n - n) % MOD;

//         while (x >= 1) {
//             s = (s + (val + (val - x + MOD) % MOD) % MOD) % MOD;
//             val = (val - 2 * x + MOD) % MOD;
//             x--;
//         }

//         int y = (s * 2022) % MOD;
//         cout << y << '\n';
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = ((((n*(n+1))%MOD)*(4*n-1))%MOD*337)%MOD;
        cout<<x<<endl;
    }
    return 0;
}
